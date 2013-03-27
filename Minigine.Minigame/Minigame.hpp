#pragma once 

#include <Game.hpp>
#include <Graphics/SpriteBatch.hpp>
#include <Graphics/Texture2D.hpp>

using Minigine::Game;
using Minigine::Graphics::SpriteBatch;
using Minigine::Graphics::Texture2D;

class Minigame : public Game
{
private:
	SpriteBatch spriteBatch;
	Texture2D texture;

public:
	Minigame();

	void Update(float elapsedTime);
	void Draw(float elapsedTime);
};