#include "Minigame.hpp"
#include <Graphics\SpriteBatch.hpp>

Minigame::Minigame()
	: Game(GraphicsDevice(1024, 768)), spriteBatch(graphicsDevice)
{
}

void Minigame::Update(float elapsedTime)
{
}

void Minigame::Draw(float elapsedTime)
{
	this->graphicsDevice.Clear(Minigine::Graphics::Color::Blue);

	this->spriteBatch.Begin();
	this->spriteBatch.Draw(Minigine::Math::Vector2F::Zero, Minigine::Math::Vector2F(100, 100), Minigine::Graphics::Color::Yellow);
	this->spriteBatch.Draw(Minigine::Math::Vector2F::Zero, Minigine::Math::Vector2F(50, 50), Minigine::Graphics::Color::Green);
	this->spriteBatch.Draw(Minigine::Math::Vector2F::Zero, Minigine::Math::Vector2F(10, 10), Minigine::Graphics::Color::White);
	this->spriteBatch.End();
}