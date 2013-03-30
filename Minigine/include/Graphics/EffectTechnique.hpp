#pragma once

#include <../Minigine.hpp>

using std::string;

namespace Minigine
{
	namespace Graphics
	{
		class MINIGINE_API EffectTechnique
		{
		public:
			unsigned int vertexShaderHandle;
			unsigned int fragmentShaderHandle;
			unsigned int programHandle;

		public:
			// TODO: shouldn't be public
			EffectTechnique()
				: vertexShaderHandle(0), fragmentShaderHandle(0), programHandle(0)
			{
			}

			EffectTechnique(string vertexShaderSource, string fragmentShaderSource);

			void Apply();
		};
	}
}