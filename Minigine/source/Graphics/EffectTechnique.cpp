#include "Graphics/EffectTechnique.hpp"
#include <Windows.h>
#include <GL/glew.h>
#include <gl/GL.h>

#include "Math/Matrix4x4F.hpp"

using std::endl;
using std::cerr;

namespace Minigine
{
	namespace Graphics
	{
		EffectTechnique::EffectTechnique(string vertexShaderSource, string fragmentShaderSource)
		{
			char shaderInfoLog[512];

			this->vertexShaderHandle = glCreateShader(GL_VERTEX_SHADER);

			const char* vertexSource = vertexShaderSource.c_str();
			glShaderSource(this->vertexShaderHandle, 1, &vertexSource, NULL);
			glCompileShader(this->vertexShaderHandle);

			int logLength = 0;
			glGetShaderInfoLog(this->vertexShaderHandle, 512, &logLength, &shaderInfoLog[0]);
			cerr << "Vertex shader log: " << shaderInfoLog << endl;

			this->fragmentShaderHandle = glCreateShader(GL_FRAGMENT_SHADER);

			const char* fragmentSource = fragmentShaderSource.c_str();
			glShaderSource(this->fragmentShaderHandle, 1, &fragmentSource, NULL);
			glCompileShader(this->fragmentShaderHandle);
			glGetShaderInfoLog(this->fragmentShaderHandle, 512, &logLength, &shaderInfoLog[0]);
			cerr << "Fragment shader log: " << shaderInfoLog << endl;

			this->programHandle = glCreateProgram();
			glAttachShader(this->programHandle, this->vertexShaderHandle);
			glAttachShader(this->programHandle, this->fragmentShaderHandle);
			glLinkProgram(this->programHandle);

			glGetProgramInfoLog(this->programHandle, 512, &logLength, &shaderInfoLog[0]);
			cerr << "Shader program log: " << shaderInfoLog << endl;
		}

		void EffectTechnique::Apply()
		{
			glUseProgram(this->programHandle);
			glEnableVertexAttribArray(0);
			glEnableVertexAttribArray(1);

			Minigine::Math::Matrix4x4F id = Minigine::Math::Matrix4x4F::CreateOrthographic(0, 800, 0, 600, -1.0, 1.0f);
			glUniformMatrix4fv(0, 1, false, &id.m[0][0]);
		}
	}
}