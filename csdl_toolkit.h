#ifndef CSDL_TOOLKIT_H
#define CSDL_TOOLKIT_H


#include "cmediatoolkit.h"
//#include "SDL.h"


class cSDL_Toolkit : public cMediaToolkit
{
	enum JoystickState { JS_CENTER,
						 JS_UP,
						 JS_UP_LEFT,
						 JS_LEFT,
						 JS_DOWN_LEFT,
						 JS_DOWN,
						 JS_DOWN_RIGHT,
						 JS_RIGHT,
						 JS_UP_RIGHT };

public:
	cSDL_Toolkit();
	~cSDL_Toolkit();
//    void PollEvents();
//    void PollEventLoop();
//    void WaitEvents();
//    void WaitEventLoop();
//    void ClearEvents();
//    void GetPointerPosition ( int *x, int *y );
//    void SetPointerPosition ( int x, int y );

private:
//	int xPos;
//	int yPos;
//	int xMove;
//	int yMove;
//	enum JoystickState jsState;
//	SDL_Joystick *joystick;
//	void HandleEvent ( SDL_Event *event );
//	void UpdatePointer();
};

#endif // CSDL_TOOLKIT_H
