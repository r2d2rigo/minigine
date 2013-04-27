#pragma once

#include "../Minigine.hpp"

namespace Minigine
{
	namespace Graphics
	{
		class GraphicsDevice;

		// TODO: should this be exported?
		class MINIGINE_API Buffer
		{
		protected:
			unsigned int handle;
			bool dynamic;
			GraphicsDevice& graphicsDevice;

		public:
			const unsigned int& GetHandle() { return this->handle; }
			const bool& IsDynamic() const { return this->dynamic; }

		public:
			Buffer(const GraphicsDevice& device, bool isDynamic = false)
				: graphicsDevice(const_cast<GraphicsDevice&>(device)), dynamic(isDynamic)
			{
			}

			virtual void SetData(int dataSize, void* data) = 0;
		};
	}
}