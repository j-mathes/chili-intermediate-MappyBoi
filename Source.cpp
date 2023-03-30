#include <iostream>
#include <string.h>
#include <conio.h>
#include <unordered_map>

#include "Vec2.h"

struct Pube
{
	std::string str;
	Vei2 vec;
	int n;
	char m;
};

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
}

int main()
{
	// create unordered map and initialize with initializer_list of std::pair
	std::unordered_map<Pube, std::string> 
		map(
		{
			{{"you", {23,40},12,92},"you"},
			{{"me", {69,40},420,69},"will"},
			{{"you", {23,40},12,91},"never"},
			{{"me", {69,69},420,69},"get this"}
		}
	);

	std::cout << map[{"you", { 23,40 }, 12, 91}];

	while (!_kbhit());
	return 0;
}