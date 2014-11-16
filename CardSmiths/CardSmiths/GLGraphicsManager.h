#ifndef GL_GRAPHICS_MANAGER_H_INCLUDED
#define GL_GRAPHICS_MANAGER_H_INCLUDED

#include "GraphicsManager.h"

#include <Windows.h>
#pragma comment(lib,"OpenGL32.lib")
#include <GL/GL.h>
#include "Vec2.h"
#include <string>

#include "Singleton.h"

class GLGraphicsManager;
typedef Singleton<GLGraphicsManager> TheGLMan;

class GLGraphicsManager: public GraphicsManager
{
public:
    GLGraphicsManager();
    ~GLGraphicsManager();

    bool Init()override;
    bool ReInit()override;
    bool Destroy()override;

    void BeginDraw()override;
    void EndDraw()override;

    
public:
    void InitGL();
   
   
private:
    HWND winHandle_;
    HGLRC glContext_;
    Vec2f windowSize_;
    std::string windowName_;
    long frameNumber_;
};


#endif
