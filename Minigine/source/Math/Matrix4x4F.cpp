#include "Math/Matrix4x4F.hpp"

namespace Minigine
{
	namespace Math
	{
		const Matrix4x4F Matrix4x4F::Identity = Matrix4x4F(1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0);
		const Matrix4x4F Matrix4x4F::Zero = Matrix4x4F();

		Matrix4x4F::Matrix4x4F()
		{
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					this->m[i][j] = 0;
				}
			}
		}

		Matrix4x4F::Matrix4x4F(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24,
				float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44)
		{
			this->m[0][0] = m11;
			this->m[0][1] = m12;
			this->m[0][2] = m13;
			this->m[0][3] = m14;

			this->m[1][0] = m21;
			this->m[1][1] = m22;
			this->m[1][2] = m23;
			this->m[1][3] = m24;

			this->m[2][0] = m31;
			this->m[2][1] = m32;
			this->m[2][2] = m33;
			this->m[2][3] = m34;

			this->m[3][0] = m41;
			this->m[3][1] = m42;
			this->m[3][2] = m43;
			this->m[3][3] = m44;
		}

		Matrix4x4F& Matrix4x4F::operator=(const Matrix4x4F& matrix)
		{
			if (this != &matrix)
			{
				for (int i = 0; i < 4; ++i)
				{
					for (int j = 0; j < 4; ++j)
					{
						this->m[i][j] = matrix.m[i][j];
					}
				}
			}

			return *this;
		}

		Matrix4x4F Matrix4x4F::CreateOrthographic(float left, float right, float top, float bottom, float near, float far)
		{
			Matrix4x4F result;

			result.m[0][0] = 2.0f / (right - left);
			result.m[1][1] = 2.0f / (top - bottom);
			result.m[2][2] = -2.0f / (far - near);
			result.m[0][3] = -(right + left) / (right - left);
			result.m[1][3] = -(top + bottom) / (top - bottom);
			result.m[2][3] = -(far + near) / (far - near);
			result.m[3][3] = 1.0f;

			return result;
		}
	}
}