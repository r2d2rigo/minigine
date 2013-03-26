#pragma once

#include <../Minigine.hpp>

namespace Minigine
{
	namespace Math
	{
		struct MINIGINE_API Vector3F
		{
		private:
			static const int XIndex = 0;
			static const int YIndex = 1;
			static const int ZIndex = 2;
			static const int VectorSize = 3;

		public:
			static const Vector3F One;
			static const Vector3F UnitX;
			static const Vector3F UnitY;
			static const Vector3F UnitZ;
			static const Vector3F Zero;

		private:
			float v[VectorSize];

		public:
			const float& GetX() const { return this->v[XIndex]; }
			const float& GetY() const { return this->v[YIndex]; }
			const float& GetZ() const { return this->v[ZIndex]; }
			void SetX(const float& x) { this->v[XIndex] = x; }
			void SetY(const float& y) { this->v[YIndex] = y; }
			void SetZ(const float& z) { this->v[ZIndex] = z; }
			float* GetVector() { return &this->v[XIndex]; }

		public:
			Vector3F();
			Vector3F(const float& x, const float& y, const float& z);
			Vector3F& operator=(const Vector3F& source); 

			bool operator==(const Vector3F& v) const;
			bool operator!=(const Vector3F& v) const;
		};
	}
}