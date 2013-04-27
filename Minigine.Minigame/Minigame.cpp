#if IOS
#import <UIKit/UIKit.h>
#endif
#include "Minigame.hpp"
#include <Graphics/SpriteBatch.hpp>

using namespace Minigine::Math;
using namespace Minigine::Graphics;

Minigame::Minigame()
	: Game(GraphicsDevice(960, 640))
{
    Game::runningInstance = this;
}

void Minigame::Initialize()
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
    
    this->spriteBatch = new SpriteBatch(graphicsDevice);
    
#if IOS
    NSString* str = [[NSBundle mainBundle] pathForResource:@"ship1" ofType:@"mtx"];
    const char *cfilename=[str UTF8String];
    
    this->texture = &Texture2D::FromFile(graphicsDevice, cfilename);
#else
    this->texture = new Texture2D(graphicsDevice, 16, 16);
	this->texture->SetData(data);
#endif
    
    this->pointBatch = new PointBatch(graphicsDevice);
}

void Minigame::Update(float elapsedTime)
{
}

void Minigame::Draw(float elapsedTime)
{
	this->graphicsDevice.Clear(Color::Black);

//	this->spriteBatch->Begin();
//	this->spriteBatch->Draw(Vector2F::Zero, Vector2F(256, 256), Color::White);
//	this->spriteBatch->Draw(Vector2F::Zero, Vector2F(128, 128), Color::Yellow);
//	this->spriteBatch->Draw(Vector2F::Zero, Vector2F(64, 64), Color::Green);
//	this->spriteBatch->Draw(*this->texture, Vector2F::Zero, Vector2F(40, 51), Color::White);
//	this->spriteBatch->Draw(this->texture, Vector2F::Zero, Color::White);
//	this->spriteBatch->End();

    this->pointBatch->Begin();
    this->pointBatch->Draw(Vector2F(100, 100), Color::Red, 10.0f);
    this->pointBatch->Draw(Vector2F(200, 100), Color::Green, 5.0f);
    this->pointBatch->End();
}