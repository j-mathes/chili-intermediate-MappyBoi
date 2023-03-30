#include <iostream>
#include <string.h>
#include <conio.h>
#include <unordered_map>

#include "Vec2.h"

struct MyStruct
{
	std::string str;
	Vei2 vec;
	int n;
	char m;
};

template <class T>
void hash_combine(std::size_t& seed, const T& v)
{
	std::hash<T> hasher;
	seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

namespace std
{
	template <>	struct hash<Vei2>
	{
		size_t operator()(const Vei2& vec) const
		{
			std::hash<int> hasher;
			auto hashx = hasher(vec.x);
			auto hashy = hasher(vec.y);

			hashx ^= hashy + 0x9e3779b9 + (hashx << 6) + (hashx >> 2);
			return hashx;
		}
	};

	template <> struct hash<MyStruct>
	{
		size_t operator()(const MyStruct& ms) const
		{
			auto seed = std::hash<std::string>()(ms.str);
			hash_combine(seed, ms.vec);
			hash_combine(seed, ms.n);
			hash_combine(seed, ms.m);
			return seed;
		}
	};

	template <> struct equal_to<MyStruct>
	{
		bool operator()(const MyStruct& lhs, const MyStruct& rhs) const
		{
			return lhs.str == rhs.str &&
				lhs.vec == rhs.vec &&
				lhs.m == rhs.m &&
				lhs.n == rhs.n;
		}
	};
}

int main()
{
	// create unordered map and initialize with initializer_list of std::pair
	std::unordered_map<MyStruct, std::string> 
		map(
		{
			{{"you", {23,40},12,92},"you"},
			{{"me", {69,40},420,69},"will"},
			{{"you", {23,40},12,91},"never"},
			{{"me", {69,69},420,69},"get this"}
		}
	);

	std::cout << map[{"you", { 23,40 }, 12, 91}];  // should return "never"

	while (!_kbhit());
	return 0;
}