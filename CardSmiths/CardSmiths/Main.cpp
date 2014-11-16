#include "Game.h"
#include "GLGraphicsManager.h"

int main(int argc, char** argv)
{
    TheGame::Instance()->SetGraphicsManager(TheGLMan::Instance());
    TheGame::Instance()->SetInputManager()
    TheGame::Instance()->Init();
}