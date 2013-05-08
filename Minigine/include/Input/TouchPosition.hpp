#pragma once

#include "../Minigine.hpp"
#include "../Math/Vector2F.hpp"

using Minigine::Math::Vector2F;

namespace Minigine
{
    namespace Input
    {
        struct MINIGINE_API TouchPosition
        {
        public:
            int ID;
            Vector2F Position;
            bool Active;
            
        public:
            TouchPosition()
            {
                this->ID = 0;
                this->Position = Vector2F::Zero;
                this->Active = false;
            }
        };
    }
}