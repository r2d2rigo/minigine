#pragma once

#if _WINDOWS
#include <gl/glew.h>
#include <Windows.h>
#include <gl/GL.h>
#endif

#if IOS
#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>

#define glClearDepth glClearDepthf

inline void CheckGLError()
{
    GLenum err = glGetError();
    if (err != GL_NO_ERROR)
    {
        throw ("GL error");
    }
}
#endif