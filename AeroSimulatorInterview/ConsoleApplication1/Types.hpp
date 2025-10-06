#pragma once

namespace Types {

	// basic 3D vector
	struct GVector
	{
		float x;
		float y;
		float z;

		constexpr GVector operator * (const GVector &other) const {
			return GVector{ x * other.x, y * other.y, z * other.z };
		}

		constexpr GVector operator * (float scalar) const {
			return GVector{ x * scalar, y * scalar, z * scalar };
		}

		constexpr GVector operator - (const GVector& other) const {
			return GVector{ x - other.x, y - other.y, z - other.z };
		}

		constexpr GVector operator - (float scalar) const {
			return GVector{ x - scalar, y - scalar, z - scalar };
		}

		GVector& operator *= (GVector other) {
			x *= other.x;
			y *= other.y;
			z *= other.z;
			return *this;
		}

		GVector& operator += (GVector other) {
			x += other.x;
			y += other.y;
			z += other.z;
			return *this;
		}

		GVector& operator -= (GVector other) {
			x -= other.x;
			y -= other.y;
			z -= other.z;
			return *this;
		}

		float length() const {
			return sqrt(x * x + y * y + z * z);
		}

		float dist(const GVector& other) const {
			return (*this - other).length();
		}

	};

}