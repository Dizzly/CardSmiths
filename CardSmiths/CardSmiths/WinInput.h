#ifndef WIN_INPUT_H_INCLUDED
#define WIN_INPUT_H_INCLUDED

#include "InputManager.h"
#include "Vec2.h"


class WinInput :public InputManager
{
public:
    enum KEY {
        // keys with ascii equivalent, eg. space, esc, enter have their ascii code.
        key_backspace = 8,
        key_tab = 9,
        key_esc = 27,
        key_space = 32,

        // other keys have the following codes:
        key_f1 = 0x80,
        key_f2,
        key_f3,
        key_f4,
        key_f5,
        key_f6,
        key_f7,
        key_f8,
        key_f9,
        key_f10,
        key_f11,
        key_f12,
        key_left,
        key_up,
        key_right,
        key_down,
        key_page_up,
        key_page_down,
        key_home,
        key_end,
        key_insert,
        key_delete,
        key_shift,
        key_ctrl,
        key_alt,

        // mouse buttons
        key_lmb,
        key_mmb,
        key_rmb,
    };

    enum KEY_STATE {
        KEY_UP,
        KEY_DOWN,
        KEY_RELEASE,
        KEY_PRESS,
    };
public:
    WinInput();
    ~WinInput()override;

    bool Init()override;
    bool Destroy()override;

    void Update()override;

public:
    unsigned Interprate(unsigned);

private:
    void SetKey(unsigned, bool);
private:
    unsigned char keys_[256];
    Vec2i mousePos_;
};


#endif