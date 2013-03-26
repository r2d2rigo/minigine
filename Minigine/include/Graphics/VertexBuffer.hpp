#pragma once

#include <../Minigine.hpp>

namespace Minigine
{
	namespace Graphics
	{
		class MINIGINE_API VertexBuffer
		{
		private:
			unsigned int handle;
			bool dynamic;

		public:
			const unsigned int& GetHandle() { return this->handle; }
			const bool& IsDynamic() const { return this->dynamic; }
			void SetData(int dataSize, void* data);

		public:
			VertexBuffer(const bool& isDynamic = false);
		};
	}
}