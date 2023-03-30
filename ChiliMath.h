/******************************************************************************************
*	Chili DirectX Framework Version 16.10.01											  *
*	ChiliMath.h																			  *
*	Copyright 2016 PlanetChili <http://www.planetchili.net>								  *
*																						  *
*	This file is part of The Chili DirectX Framework.									  *
*																						  *
*	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
*	it under the terms of the GNU General Public License as published by				  *
*	the Free Software Foundation, either version 3 of the License, or					  *
*	(at your option) any later version.													  *
*																						  *
*	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
*	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
*	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
*	GNU General Public License for more details.										  *
*																						  *
*	You should have received a copy of the GNU General Public License					  *
*	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
******************************************************************************************/
#pragma once

#include <cmath>

static constexpr double PI_D = 3.14159265358979323846;
static constexpr float PI = (float)PI_D;

// integer division with round up if remainder exists
inline int div_int_ceil(int lhs, int rhs)
{
	return (lhs + rhs - 1) / rhs;
}

template<typename T>
inline T clamp(T x, T min, T max)
{
	return std::min(max, std::max(min, x));
}