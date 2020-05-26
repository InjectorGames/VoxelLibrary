#pragma once
#include <voxel/defines.hpp>

namespace VOXEL_NAMESPACE
{
	template<class T>
	struct Vec3
	{
		T x;
		T y;
		T z;

		Vec3(const T _x = T(),
			const T _y = T(),
			const T _z = T()) :
			x(_x),
			y(_y),
			z(_z)
		{}

		inline const Vec3 operator+(const Vec3<T>& other) const noexcept
		{
			return Vec3(x + other.x, y + other.y, z + other.z);
		}
		inline const Vec3 operator-(const Vec3<T>& other) const noexcept
		{
			return Vec3(x - other.x, y - other.y, z - other.z);
		}
		inline const bool operator<(const Vec3<T>& other) const noexcept
		{
			if (x < other.x) return true;
			if (x > other.x) return false;
			if (y < other.y) return true;
			if (y > other.y) return false;
			if (z < other.z) return true;
			if (z > other.z) return false;
			return false;
		}
		inline const bool operator>(const Vec3<T>& other) const noexcept
		{
			if (x > other.x) return true;
			if (x < other.x) return false;
			if (y > other.y) return true;
			if (y < other.y) return false;
			if (z > other.z) return true;
			if (z < other.z) return false;
			return false;
		}
		inline const bool operator==(const Vec3<T>& other) const noexcept
		{
			return x == other.x && y == other.y && z == other.z;
		}
		inline const bool operator!=(const Vec3<T>& other)  const noexcept
		{
			return x != other.x && y != other.y && z != other.z;
		}
	};
}