#include "Graphics/Color.hpp"

namespace Minigine
{
	namespace Graphics
	{
		const Color Color::Black(0, 0, 0, 255);
		const Color Color::Blue(0, 0, 255, 255);
		const Color Color::Green(0, 255, 0, 255);
		const Color Color::Red(255, 0, 0, 255);
		const Color Color::White(255, 255, 255, 255);
		const Color Color::Yellow(255, 255, 0, 255);

		Color::Color() 
		{
			this->SetR(0);
			this->SetG(0);
			this->SetB(0);
			this->SetA(0);
		}

		Color::Color(const byte& r, const byte& g, const byte &b)
		{
			this->SetR(r);
			this->SetG(g);
			this->SetB(b);
			this->SetA(255);
		}

		Color::Color(const byte& r, const byte& g, const byte &b, const byte &a)
		{
			this->SetR(r);
			this->SetG(g);
			this->SetB(b);
			this->SetA(a);			
		}

		Color& Color::operator=(const Color& source)
		{
			if (this != &source)
			{
				this->SetR(source.GetR());
				this->SetG(source.GetG());
				this->SetB(source.GetB());
				this->SetA(source.GetA());			
			}

			return *this;
		}

		bool Color::operator==(const Color& c) const
		{
			return (this->GetR() == c.GetR()) && (this->GetG() == c.GetG()) && (this->GetB() && c.GetB()) && (this->GetA() == c.GetA()); 
		}

		bool Color::operator!=(const Color& c) const
		{
			return !(*this == c);
		}
        
        Color& Color::Lerp(const Color &c1, const Color &c2, const float& amount)
        {
            Color c;
            float inverseAmount = 1.0f - amount;
            
            // TODO: check for overflow?
            c.SetR((byte)((c1.GetR() * amount) + (c2.GetR() * inverseAmount)));
            c.SetG((byte)((c1.GetG() * amount) + (c2.GetG() * inverseAmount)));
            c.SetB((byte)((c1.GetB() * amount) + (c2.GetB() * inverseAmount)));
            c.SetA((byte)((c1.GetA() * amount) + (c2.GetA() * inverseAmount)));
            
            return c;
        }
	}
}