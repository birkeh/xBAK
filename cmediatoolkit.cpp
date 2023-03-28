#include "cexception.h"
#include "cmediatoolkit.h"
#include "csdl_toolkit.h"


cMediaToolkit* cMediaToolkit::m_instance = 0;


cMediaToolkit::cMediaToolkit()
//	: audio(0)
//	, clock(0)
//	, video(0)
//	, eventLoopRunning(false)
//	, keyboardListeners()
//	, pointerButtonListeners()
//	, pointerMotionListeners()
//	, timerListeners()
//	, loopListeners()
{
}

cMediaToolkit::~cMediaToolkit()
{
//    keyboardListeners.clear();
//    pointerButtonListeners.clear();
//    pointerMotionListeners.clear();
//    timerListeners.clear();
//    loopListeners.clear();
}

cMediaToolkit* cMediaToolkit::getInstance()
{
	if(!m_instance)
		m_instance = new cSDL_Toolkit();
	return m_instance;
}

void cMediaToolkit::cleanUp()
{
	if(m_instance)
	{
		delete(m_instance);
		m_instance = 0;
	}
}

//Audio*
//MediaToolkit::GetAudio() const
//{
//	return audio;
//}

//Clock*
//MediaToolkit::GetClock() const
//{
//	return clock;
//}

//Video*
//MediaToolkit::GetVideo() const
//{
//	return video;
//}

//void
//MediaToolkit::AddKeyboardListener(KeyboardEventListener *kel)
//{
//	keyboardListeners.push_back(kel);
//}

//void
//MediaToolkit::RemoveKeyboardListener(KeyboardEventListener *kel)
//{
//	keyboardListeners.remove(kel);
//}

//void
//MediaToolkit::AddPointerButtonListener(PointerButtonEventListener *pbel)
//{
//	pointerButtonListeners.push_back(pbel);
//}

//void
//MediaToolkit::RemovePointerButtonListener(PointerButtonEventListener *pbel)
//{
//	pointerButtonListeners.remove(pbel);
//}

//void
//MediaToolkit::AddPointerMotionListener(PointerMotionEventListener *pmel)
//{
//	pointerMotionListeners.push_back(pmel);
//}

//void
//MediaToolkit::RemovePointerMotionListener(PointerMotionEventListener *pmel)
//{
//	pointerMotionListeners.remove(pmel);
//}

//void
//MediaToolkit::AddTimerListener(TimerEventListener *tel)
//{
//	timerListeners.push_back(tel);
//}

//void
//MediaToolkit::RemoveTimerListener(TimerEventListener *tel)
//{
//	timerListeners.remove(tel);
//}

//void
//MediaToolkit::AddUpdateListener(LoopEventListener *lel)
//{
//	loopListeners.push_back(lel);
//}

//void
//MediaToolkit::RemoveUpdateListener(LoopEventListener *lel)
//{
//	loopListeners.remove(lel);
//}

//void
//MediaToolkit::TerminateEventLoop()
//{
//	eventLoopRunning = false;
//}
