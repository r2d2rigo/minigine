#include "Minigame.hpp"
#include <Graphics\SpriteBatch.hpp>

using namespace Minigine::Math;
using namespace Minigine::Graphics;

Minigame::Minigame()
	: Game(GraphicsDevice(800, 600)), spriteBatch(graphicsDevice), texture(graphicsDevice, 16, 16), effect(Effect())
{
	byte data[4 * 16 * 16];

	for (int i = 0; i < 16; ++i)
	{
		for (int j = 0; j < 16; ++j)
		{
			if (i % 2 == 0)
			{
				if (j % 2 == 0)
				{
					data[i * 64 + j * 4] = 255;
					data[i * 64 + j * 4 + 1] = 255;
					data[i * 64 + j * 4 + 2] = 255;
					data[i * 64 + j * 4 + 3] = 255;
				}
				else
				{
					data[i * 64 + j * 4] = 0;
					data[i * 64 + j * 4 + 1] = 0;
					data[i * 64 + j * 4 + 2] = 0;
					data[i * 64 + j * 4 + 3] = 255;
				}
			}
			else
			{
				if (j % 2 == 0)
				{
					data[i * 64 + j * 4] = 0;
					data[i * 64 + j * 4 + 1] = 0;
					data[i * 64 + j * 4 + 2] = 0;
					data[i * 64 + j * 4 + 3] = 255;
				}
				else
				{
					data[i * 64 + j * 4] = 255;
					data[i * 64 + j * 4 + 1] = 255;
					data[i * 64 + j * 4 + 2] = 255;
					data[i * 64 + j * 4 + 3] = 255;
				}
			}
		}
	}

	this->texture.SetData(data);

	//Minigine::Graphics::EffectTechnique technique("attribute vec3 position; void main() { gl_Position = vec4(position, 1.0); } ", "void main() { gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0); } ");
	//this->effect.AddTechnique("test", technique);
}

void Minigame::Update(float elapsedTime)
{
}

void Minigame::Draw(float elapsedTime)
{
	this->graphicsDevice.Clear(Color::Blue);

	this->spriteBatch.Begin();
//	this->spriteBatch.Draw(Vector2F::Zero, Vector2F(100, 100), Color::Yellow);
//	this->spriteBatch.Draw(Vector2F::Zero, Vector2F(50, 50), Color::Green);
//	this->spriteBatch.Draw(Vector2F::Zero, Vector2F(10, 10), Color::White);
	this->spriteBatch.Draw(this->texture, Vector2F::Zero, Vector2F(128, 128), Color::Red);
	this->spriteBatch.Draw(this->texture, Vector2F::Zero, Color::White);
	this->spriteBatch.End();
}