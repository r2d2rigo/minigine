#include "Minigame.hpp"
#include <Graphics\SpriteBatch.hpp>

using namespace Minigine::Math;
using namespace Minigine::Graphics;

Minigame::Minigame()
	: Game(GraphicsDevice(800, 600)), spriteBatch(graphicsDevice)
{
}

void Minigame::Update(float elapsedTime)
{
}

void Minigame::Draw(float elapsedTime)
{
	this->graphicsDevice.Clear(Color::Blue);

	this->spriteBatch.Begin();
	this->spriteBatch.Draw(Vector2F::Zero, Vector2F(100, 100), Color::Yellow);
	this->spriteBatch.Draw(Vector2F::Zero, Vector2F(50, 50), Color::Green);
	this->spriteBatch.Draw(Vector2F::Zero, Vector2F(10, 10), Color::White);
	this->spriteBatch.End();
}