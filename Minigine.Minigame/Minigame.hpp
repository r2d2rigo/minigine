#pragma once 

#include <Game.hpp>
#include <Graphics/SpriteBatch.hpp>
#include <Graphics/Texture2D.hpp>
#include <Graphics/Effect.hpp>

using Minigine::Game;
using Minigine::Graphics::SpriteBatch;
using Minigine::Graphics::Texture2D;
using Minigine::Graphics::Effect;

class Minigame : public Game
{
private:
	SpriteBatch* spriteBatch;
	Texture2D* texture;

public:
	Minigame();

    void Initialize();
	void Update(float elapsedTime);
	void Draw(float elapsedTime);
};