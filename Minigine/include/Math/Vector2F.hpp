#pragma once

#include <../Minigine.hpp>

namespace Minigine
{
	namespace Math
	{
		struct MINIGINE_API Vector2F
		{
		private:
			static const int XIndex = 0;
			static const int YIndex = 1;
			static const int VectorSize = 2;

		public:
			static const Vector2F One;
			static const Vector2F UnitX;
			static const Vector2F UnitY;
			static const Vector2F Zero;

		private:
			float v[VectorSize];

		public:
			const float& GetX() const { return this->v[XIndex]; }
			const float& GetY() const { return this->v[YIndex]; }
			void SetX(const float& x) { this->v[XIndex] = x; }
			void SetY(const float& y) { this->v[YIndex] = y; }
			float* GetVector() { return &this->v[XIndex]; }

		public:
			Vector2F();
			Vector2F(const float& x, const float& y);
			Vector2F& operator=(const Vector2F& source); 

			bool operator==(const Vector2F& v) const;
			bool operator!=(const Vector2F& v) const;
			Vector2F& operator+=(const Vector2F& other);
			Vector2F& operator-=(const Vector2F& other);
			Vector2F operator+(const Vector2F& other) const;
			Vector2F operator-(const Vector2F& other) const;
		};
	}
}