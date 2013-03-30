#pragma once

#include <../Minigine.hpp>

namespace Minigine
{
	namespace Math
	{
		struct MINIGINE_API Matrix4x4F
		{
		public:
			static const Matrix4x4F Identity;
			static const Matrix4x4F Zero;

		public:
			float m[4][4];

		public:
			Matrix4x4F();
			Matrix4x4F(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24,
				float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44);
			Matrix4x4F& operator=(const Matrix4x4F& matrix);

			static Matrix4x4F CreateOrthographic(float left, float right, float top, float bottom, float near, float far);
		};
	}
}