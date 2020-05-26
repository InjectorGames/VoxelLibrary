#pragma once
#include <voxel/defines.hpp>

namespace VOXEL_NAMESPACE
{
	template<class T>
	struct Vec2
	{
		T x;
		T y;

		Vec2(const T _x = T(),
			const T _y = T()) :
			x(_x),
			y(_y)
		{}

		inline const Vec2 operator+(const Vec2<T>& other) const noexcept
		{
			return Vec2(x + other.x, y + other.y);
		}
		inline const Vec2 operator-(const Vec2<T>& other) const noexcept
		{
			return Vec2(x - other.x, y - other.y);
		}
		inline const bool operator<(const Vec2<T>& other) const noexcept
		{
			if (x < other.x) return true;
			if (x > other.x) return false;
			if (y < other.y) return true;
			if (y > other.y) return false;
			return false;
		}
		inline const bool operator>(const Vec2<T>& other) const noexcept
		{
			if (x > other.x) return true;
			if (x < other.x) return false;
			if (y > other.y) return true;
			if (y < other.y) return false;
			return false;
		}
		inline const bool operator==(const Vec2<T>& other) const noexcept
		{
			return x == other.x && y == other.y;
		}
		inline const bool operator!=(const Vec2<T>& other)  const noexcept
		{
			return x != other.x && y != other.y;
		}
	};
}