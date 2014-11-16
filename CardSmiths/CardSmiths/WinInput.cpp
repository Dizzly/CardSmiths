#include "WinInput.h"

//to get access to memset
#include <string.h>
//--


//For windows PeekMessage
#include <Windows.h>
//




WinInput::WinInput()
{
    memset(keys_, 0, sizeof(keys_));
}

WinInput::~WinInput()
{}

bool WinInput::Init()
{
    
    return true;
}

bool WinInput::Destroy()
{
    return true;
}
void WinInput::Update()
{
    MSG msg;
    while (PeekMessage(&msg, 0, 0, 0, TRUE))
    {
        if (msg.message == WM_KEYDOWN || msg.message == WM_KEYUP) {
            SetKey(Interprate((unsigned)msg.wParam), msg.message == WM_KEYDOWN);
        }
        else if (msg.message == WM_SYSKEYDOWN || msg.message == WM_SYSKEYUP) {
            SetKey(Interprate((unsigned)msg.wParam), msg.message == WM_SYSKEYDOWN);
        }
        else if (msg.message == WM_MOUSEMOVE) {
            mousePos_ = Vec2i(msg.lParam & 0xffff, msg.lParam >> 16);
        }
        else if (msg.message == WM_LBUTTONDOWN || msg.message == WM_LBUTTONUP) {
            SetKey(Interprate(key_lmb), msg.message == WM_LBUTTONDOWN);
        }
        else if (msg.message == WM_MBUTTONDOWN || msg.message == WM_MBUTTONUP) {
            SetKey(Interprate(key_mmb), msg.message == WM_MBUTTONDOWN);
        }
        else if (msg.message == WM_RBUTTONDOWN || msg.message == WM_RBUTTONUP) {
            SetKey(Interprate(key_rmb), msg.message == WM_RBUTTONDOWN);
        }
        DispatchMessage(&msg);
    }
}

unsigned WinInput::Interprate(unsigned key)
{
    switch (key) {
    case VK_SHIFT: return key_shift;
    case VK_CONTROL: return key_ctrl;
    case VK_MENU: return key_alt;

    case VK_END: return key_end;
    case VK_HOME: return key_home;
    case VK_LEFT: return key_left;
    case VK_UP: return key_up;
    case VK_RIGHT: return key_right;
    case VK_DOWN: return key_down;
    case VK_INSERT: return key_insert;
    case VK_DELETE: return key_delete;

    case VK_F1: return key_f1;
    case VK_F2: return key_f2;
    case VK_F3: return key_f3;
    case VK_F4: return key_f4;
    case VK_F5: return key_f5;
    case VK_F6: return key_f6;
    case VK_F7: return key_f7;
    case VK_F8: return key_f8;
    case VK_F9: return key_f9;
    case VK_F10: return key_f10;
    case VK_F11: return key_f11;
    case VK_F12: return key_f12;
    }
    return key;
}

void WinInput::SetKey(unsigned key, bool state)
{
    keys_[key & 0xff] = state ? 1 : 0;
}

