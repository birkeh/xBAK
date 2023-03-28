#ifndef CGAMEAPPLICATION_H
#define CGAMEAPPLICATION_H


//#include "ConfigResource.h"
//#include "GameResource.h"
//#include "GameState.h"


class cGameApplication
//		: public KeyboardEventListener
//		, public PointerButtonEventListener
//		, public TimerEventListener
{
public:
	~cGameApplication();
	static cGameApplication*		getInstance();
	static void						cleanUp();
//	Preferences* GetPreferences();
//	Game* GetGame();
//	void PlayIntro();
//	void StartNewGame();
//	void QuitGame();
//	void SaveConfig();
	void							run();
//	void KeyPressed ( const KeyboardEvent& kbe );
//	void KeyReleased ( const KeyboardEvent& kbe );
//	void PointerButtonPressed ( const PointerButtonEvent& pbe );
//	void PointerButtonReleased ( const PointerButtonEvent& pbe );
//	void TimerExpired ( const TimerEvent& te );

private:
//	friend class GameState;
//	bool done;
//	bool inputGrabbed;
//	ConfigResource *config;
//	GameResource *game;
//	GameState *state;
//	int screenSaveCount;
	static cGameApplication*		m_instance;
//	void SetState ( GameState *st );

protected:
	cGameApplication();
};

/*
class GameApplication
: public KeyboardEventListener
, public PointerButtonEventListener
, public TimerEventListener
{
	private:
		friend class GameState;
		bool done;
		bool inputGrabbed;
		ConfigResource *config;
		GameResource *game;
		GameState *state;
		int screenSaveCount;
		static GameApplication *instance;
		void SetState ( GameState *st );
	protected:
		GameApplication();
	public:
		~GameApplication();
		static GameApplication* GetInstance();
		static void CleanUp();
		Preferences* GetPreferences();
		Game* GetGame();
		void PlayIntro();
		void StartNewGame();
		void QuitGame();
		void SaveConfig();
		void Run();
		void KeyPressed ( const KeyboardEvent& kbe );
		void KeyReleased ( const KeyboardEvent& kbe );
		void PointerButtonPressed ( const PointerButtonEvent& pbe );
		void PointerButtonReleased ( const PointerButtonEvent& pbe );
		void TimerExpired ( const TimerEvent& te );
};
*/

#endif // CGAMEAPPLICATION_H
