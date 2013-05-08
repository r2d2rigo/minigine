#pragma once

#include "../Minigine.hpp"
#include "TouchPosition.hpp"

namespace Minigine
{
    namespace Input
    {
        class MINIGINE_API Touch
        {
            // TODO: make this private
        public:
            static TouchPosition touches[4];
            
        public:
            static void AddTouch(const TouchPosition& touch);
            static void UpdateTouch(const TouchPosition& touch);
            static void RemoveTouch(const TouchPosition& touch);
        };
    }
}