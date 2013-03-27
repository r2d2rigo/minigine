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
	GetGraphicsDevice().Clear(Minigine::Graphics::Color::Blue);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	gluOrtho2D(0.0f, this->graphicsDevice.GetScreenWidth(), this->graphicsDevice.GetScreenHeight(), 0.0f);
    //gluPerspective(90.f, 1.f, 1.f, 500.f);

        // Apply some transformations
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        //glTranslatef(0.f, 0.f, -200.f);
        //glRotatef(Clock.GetElapsedTime() * 50, 1.f, 0.f, 0.f);
        //glRotatef(Clock.GetElapsedTime() * 30, 0.f, 1.f, 0.f);
        //glRotatef(Clock.GetElapsedTime() * 90, 0.f, 0.f, 1.f);

        // Draw a cube


	this->spriteBatch.Begin();
	this->spriteBatch.Draw(Minigine::Math::Vector2F::Zero, Minigine::Math::Vector2F(100, 100), Minigine::Graphics::Color::Yellow);
	this->spriteBatch.Draw(Minigine::Math::Vector2F::Zero, Minigine::Math::Vector2F(50, 50), Minigine::Graphics::Color::Green);
	this->spriteBatch.Draw(Minigine::Math::Vector2F::Zero, Minigine::Math::Vector2F(10, 10), Minigine::Graphics::Color::White);
	this->spriteBatch.End();


		//Minigine::Graphics::Color c = Minigine::Graphics::Color::Blue;
		//glColor4ubv(Minigine::Graphics::Color::Red.GetVector());

  //      glBegin(GL_QUADS);

  //          glTexCoord2f(0, 0); glVertex3f(-50.f, -50.f, -50.f);
  //          glTexCoord2f(0, 1); glVertex3f(-50.f,  50.f, -50.f);
  //          glTexCoord2f(1, 1); glVertex3f( 50.f,  50.f, -50.f);
  //          glTexCoord2f(1, 0); glVertex3f( 50.f, -50.f, -50.f);

  //          glTexCoord2f(0, 0); glVertex3f(-50.f, -50.f, 50.f);
  //          glTexCoord2f(0, 1); glVertex3f(-50.f,  50.f, 50.f);
  //          glTexCoord2f(1, 1); glVertex3f( 50.f,  50.f, 50.f);
  //          glTexCoord2f(1, 0); glVertex3f( 50.f, -50.f, 50.f);

  //          glTexCoord2f(0, 0); glVertex3f(-50.f, -50.f, -50.f);
  //          glTexCoord2f(0, 1); glVertex3f(-50.f,  50.f, -50.f);
  //          glTexCoord2f(1, 1); glVertex3f(-50.f,  50.f,  50.f);
  //          glTexCoord2f(1, 0); glVertex3f(-50.f, -50.f,  50.f);

  //          glTexCoord2f(0, 0); glVertex3f(50.f, -50.f, -50.f);
  //          glTexCoord2f(0, 1); glVertex3f(50.f,  50.f, -50.f);
  //          glTexCoord2f(1, 1); glVertex3f(50.f,  50.f,  50.f);
  //          glTexCoord2f(1, 0); glVertex3f(50.f, -50.f,  50.f);

  //          glTexCoord2f(0, 1); glVertex3f(-50.f, -50.f,  50.f);
  //          glTexCoord2f(0, 0); glVertex3f(-50.f, -50.f, -50.f);
  //          glTexCoord2f(1, 0); glVertex3f( 50.f, -50.f, -50.f);
  //          glTexCoord2f(1, 1); glVertex3f( 50.f, -50.f,  50.f);

  //          glTexCoord2f(0, 1); glVertex3f(-50.f, 50.f,  50.f);
  //          glTexCoord2f(0, 0); glVertex3f(-50.f, 50.f, -50.f);
  //          glTexCoord2f(1, 0); glVertex3f( 50.f, 50.f, -50.f);
  //          glTexCoord2f(1, 1); glVertex3f( 50.f, 50.f,  50.f);

  //      glEnd();

}