#pragma once 

#include <Game.hpp>
#include <Graphics/SpriteBatch.hpp>

using Minigine::Game;
using Minigine::Graphics::SpriteBatch;

class Minigame : public Game
{
private:
	SpriteBatch spriteBatch;

public:
	Minigame();

	void Update(float elapsedTime);
	void Draw(float elapsedTime);
};