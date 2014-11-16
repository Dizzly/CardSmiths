#include "GLGraphicsManager.h"



GLGraphicsManager::GLGraphicsManager() :windowSize_(768,768)
{
}

GLGraphicsManager::~GLGraphicsManager()
{
}

bool GLGraphicsManager::Init()
{


    HINSTANCE instance = (HINSTANCE)GetModuleHandle(0);
    HBRUSH brush =(HBRUSH)GetStockObject(NULL_BRUSH);
    HICON icon = LoadIcon(0, IDI_ASTERISK);
    HCURSOR cursor = LoadCursor(0, IDC_ARROW);

    const WNDCLASSW wndclass = {
        CS_HREDRAW | CS_VREDRAW, DefWindowProc, 0, 0, instance,
        icon, cursor, brush, 0, L"MyClass"

    };
    RegisterClassW(&wndclass);

    glContext_ = nullptr;
    winHandle_ = CreateWindowW(L"MyClass", L"Window",
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
        windowSize_.x, windowSize_.y, NULL, NULL,
        wndclass.hInstance, (LPVOID)this);
    
   

    ShowWindow(winHandle_, SW_SHOW);
    UpdateWindow(winHandle_);
    return true;
}

void GLGraphicsManager::InitGL()
{
    const PIXELFORMATDESCRIPTOR pfd = {
        sizeof(PIXELFORMATDESCRIPTOR),  //  size of this pfd  
        1,                     // version number  
        PFD_DRAW_TO_WINDOW |   // support window  
        PFD_SUPPORT_OPENGL |   // support OpenGL  
        PFD_DOUBLEBUFFER,      // double buffered  
        PFD_TYPE_RGBA,         // RGBA type  
        24,                    // 24-bit color depth  
        0, 0, 0, 0, 0, 0,      // color bits ignored  
        0,                     // no alpha buffer  
        0,                     // shift bit ignored  
        0,                     // no accumulation buffer  
        0, 0, 0, 0,            // accum bits ignored  
        32,                    // 32-bit z-buffer      
        0,                     // no stencil buffer  
        0,                     // no auxiliary buffer  
        PFD_MAIN_PLANE,        // main layer  
        0,                     // reserved  
        0, 0, 0                // layer masks ignored  
    };

    HDC hdc = GetDC(winHandle_);

    int pixel_format = ChoosePixelFormat(hdc, &pfd);

    SetPixelFormat(hdc, pixel_format, &pfd);

    glContext_ = wglCreateContext(hdc);

    ReleaseDC(winHandle_, hdc);


}

bool GLGraphicsManager::ReInit()
{
    return false;
}

bool GLGraphicsManager::Destroy()
{
    return false;
}

void GLGraphicsManager::BeginDraw()
{
   

    
}

void GLGraphicsManager::EndDraw()
{
    HDC hdc = GetDC(winHandle_);
    wglMakeCurrent(hdc, glContext_);

    SwapBuffers(hdc);

    ++frameNumber_;
    wglMakeCurrent(hdc, NULL);
    ReleaseDC(winHandle_, hdc);
}

