#pragma once

#include "../Minigine.hpp"
#include "Vector2F.hpp"

namespace Minigine
{
	namespace Math
	{
		struct MINIGINE_API RectangleF
		{
		private:
			Vector2F position;
			Vector2F size;

		public:
			const Vector2F& GetPosition() const { return this->position; }
			const Vector2F& GetSize() const { return this->size; }

		public:
			RectangleF();
			RectangleF(const float& x, const float& y, const float& width, const float& height) 
				: position(x, y), size (width, height)
			{
			}
		};
	}
}