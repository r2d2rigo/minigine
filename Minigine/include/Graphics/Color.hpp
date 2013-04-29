#pragma once

#include "../Minigine.hpp"

namespace Minigine
{
	namespace Graphics
	{
		struct MINIGINE_API Color
		{
		private:
			static const int RIndex = 0;
			static const int GIndex = 1;
			static const int BIndex = 2;
			static const int AIndex = 3;
			static const int VectorSize = 4;

		private:
			byte components[VectorSize];

		public:
			static const Color Black;
			static const Color Blue;
			static const Color Green;
			static const Color Red;
			static const Color White;
			static const Color Yellow;

		public:
			const byte& GetR() const { return this->components[RIndex]; }
			const byte& GetG() const { return this->components[GIndex]; }
			const byte& GetB() const { return this->components[BIndex]; }
			const byte& GetA() const { return this->components[AIndex]; }
			const byte* GetVector() const { return &this->components[RIndex]; } 
			void SetR(const byte& r) { this->components[RIndex] = r; }
			void SetG(const byte& g) { this->components[GIndex] = g; }
			void SetB(const byte& b) { this->components[BIndex] = b; }
			void SetA(const byte& a) { this->components[AIndex] = a; }

		public:
			Color();
			Color(const byte& r, const byte& g, const byte &b);
			Color(const byte& r, const byte& g, const byte &b, const byte &a);
			Color& operator=(const Color& source); 			

			bool operator==(const Color& c) const;
			bool operator!=(const Color& c) const;
            
            static Color Lerp(const Color& c1, const Color& c2, const float& amount);
		};
	}
}