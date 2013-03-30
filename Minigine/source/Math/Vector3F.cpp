#include "Math/Vector3F.hpp"

namespace Minigine
{
	namespace Math
	{
		const Vector3F Vector3F::One = Vector3F(1, 1, 1);
		const Vector3F Vector3F::UnitX = Vector3F(1, 0, 0);
		const Vector3F Vector3F::UnitY = Vector3F(0, 1, 0);
		const Vector3F Vector3F::UnitZ = Vector3F(0, 0, 1);
		const Vector3F Vector3F::Zero = Vector3F(0, 0, 0);

		Vector3F::Vector3F()
		{
			this->SetX(0);
			this->SetY(0);
			this->SetZ(0);
		}

		Vector3F::Vector3F(const float& x, const float& y, const float& z)
		{
			this->SetX(x);
			this->SetY(y);
			this->SetZ(z);
		}

		Vector3F& Vector3F::operator=(const Vector3F& source)
		{
			if (this != &source)
			{
				this->SetX(source.GetX());
				this->SetY(source.GetY());
				this->SetZ(source.GetZ());
			}
	
			return *this;
		}

		bool Vector3F::operator==(const Vector3F& v) const
		{
			return (this->GetX() == v.GetX()) && (this->GetY() == v.GetY()) && (this->GetZ() == v.GetZ());
		}

		bool Vector3F::operator!=(const Vector3F& v) const
		{
			return !(*this == v);
		}
	}
}