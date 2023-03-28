#ifndef CMEDIATOOLKIT_H
#define CMEDIATOOLKIT_H


#include <list>

//#include "Audio.h"
//#include "Clock.h"
//#include "EventListener.h"
//#include "Video.h"


class cMediaToolkit
{
public:
	cMediaToolkit();
	virtual ~cMediaToolkit();
	static cMediaToolkit*					getInstance();
	static void								cleanUp();
//    Audio* GetAudio() const;
//    Clock* GetClock() const;
//    Video* GetVideo() const;
//    void AddKeyboardListener ( KeyboardEventListener *kel );
//    void RemoveKeyboardListener ( KeyboardEventListener *kel );
//    void AddPointerButtonListener ( PointerButtonEventListener *pbel );
//    void RemovePointerButtonListener ( PointerButtonEventListener *pbel );
//    void AddPointerMotionListener ( PointerMotionEventListener *pmel );
//    void RemovePointerMotionListener ( PointerMotionEventListener *pmel );
//    void AddTimerListener ( TimerEventListener *tel );
//    void RemoveTimerListener ( TimerEventListener *tel );
//    void AddUpdateListener ( LoopEventListener *lel );
//    void RemoveUpdateListener ( LoopEventListener *lel );
//    void TerminateEventLoop();
//    virtual void PollEvents() = 0;
//    virtual void PollEventLoop() = 0;
//    virtual void WaitEvents() = 0;
//    virtual void WaitEventLoop() = 0;
//    virtual void ClearEvents() = 0;
//    virtual void GetPointerPosition ( int *x, int *y ) = 0;
//    virtual void SetPointerPosition ( int x, int y ) = 0;

private:
	static cMediaToolkit*					m_instance;

protected:
//    Audio *audio;
//    Clock *clock;
//    Video *video;
//    bool eventLoopRunning;
//    std::list<KeyboardEventListener *> keyboardListeners;
//    std::list<PointerButtonEventListener *> pointerButtonListeners;
//    std::list<PointerMotionEventListener *> pointerMotionListeners;
//    std::list<TimerEventListener *> timerListeners;
//    std::list<LoopEventListener *> loopListeners;
};


#endif // CMEDIATOOLKIT_H
