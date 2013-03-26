#include "Math/Vector2F.hpp"

namespace Minigine
{
	namespace Math
	{
		const Vector2F Vector2F::One(1, 1);
		const Vector2F Vector2F::UnitX(1, 0);
		const Vector2F Vector2F::UnitY(0, 1);
		const Vector2F Vector2F::Zero(0, 0);

		Vector2F::Vector2F() 
		{
			this->SetX(0);
			this->SetY(0);
		}

		Vector2F::Vector2F(const float& x, const float& y)
		{
			this->SetX(x);
			this->SetY(y);
		}

		Vector2F& Vector2F::operator=(const Vector2F& source)
		{
			if (this != &source)
			{
				this->SetX(source.GetX());
				this->SetY(source.GetY());
			}
	
			return *this;
		}

		bool Vector2F::operator==(const Vector2F& v) const
		{
			return (this->GetX() == v.GetX()) && (this->GetY() == v.GetY());
		}

		bool Vector2F::operator!=(const Vector2F& v) const
		{
			return !(*this == v);
		}
	}
}