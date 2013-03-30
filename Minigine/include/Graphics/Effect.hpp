#pragma once

#include <map>
#include <../Minigine.hpp>
#include "EffectTechnique.hpp"

using std::string;
using std::map;

namespace Minigine
{
	namespace Graphics
	{
		class MINIGINE_API Effect
		{
		private:
			map<string, EffectTechnique> techniques;
//			EffectTechnique& currentTechnique;

		public:
			// TODO: shouldn't be public
			Effect() 
			{
			}

			void AddTechnique(string techniqueName, EffectTechnique technique);
		};
	}
}