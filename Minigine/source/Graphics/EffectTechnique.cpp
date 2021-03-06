#include <../GLConfig.hpp>
#include "Graphics/EffectTechnique.hpp"

#include "Math/Matrix4x4F.hpp"
#include <iostream>

using std::endl;
using std::cout;

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
			cout << "Vertex shader log: " << shaderInfoLog << endl;

			this->fragmentShaderHandle = glCreateShader(GL_FRAGMENT_SHADER);

			const char* fragmentSource = fragmentShaderSource.c_str();
			glShaderSource(this->fragmentShaderHandle, 1, &fragmentSource, NULL);
			glCompileShader(this->fragmentShaderHandle);
			glGetShaderInfoLog(this->fragmentShaderHandle, 512, &logLength, &shaderInfoLog[0]);
			cout << "Fragment shader log: " << shaderInfoLog << endl;
            
			this->programHandle = glCreateProgram();
			glAttachShader(this->programHandle, this->vertexShaderHandle);
			glAttachShader(this->programHandle, this->fragmentShaderHandle);
            
            glBindAttribLocation(this->programHandle, 0, "position");
            glBindAttribLocation(this->programHandle, 1, "color");
            glBindAttribLocation(this->programHandle, 2, "size");
            
			glLinkProgram(this->programHandle);

			glGetProgramInfoLog(this->programHandle, 512, &logLength, &shaderInfoLog[0]);
			cout << "Shader program log: " << shaderInfoLog << endl;
		}

		void EffectTechnique::Apply()
		{
			glUseProgram(this->programHandle);

			Minigine::Math::Matrix4x4F id = Minigine::Math::Matrix4x4F::CreateOrthographic(0, 480, 0, 320, -1.0, 1.0f);
			glUniformMatrix4fv(0, 1, false, &id.m[0][0]);
		}
	}
}