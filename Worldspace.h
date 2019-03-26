#pragma once


#include "Map.h"
#include "XP.h"
#include "UserInterface.h"


class Worldspace //: IHapiSpritesInputListener
{ 
public:
	Worldspace();
	~Worldspace();
	void Initialise();
	HAPISPACE::VectorI GetScreenSize();
	void ResetFile();
	

private:
	int m_width{ 1280 };
	int m_height{ 800 };
	int m_difficulty{ 1 };
	int scrollValue = 0;
	
	//UserInterface *Menu{ nullptr };
	class XP xp;

	void Game();
	
	void ConfigLoad();
	void SaveFile();
	void LoadFile();
	


/*
	// Called when HAPI Sprites detects a key event (repeatadly for key down, once for key up)
	void OnKeyEvent(EKeyEvent keyEvent, BYTE keyCode) override {}

	// Called when HAPI detects a mouse event other than mouse move
	void OnMouseEvent(EMouseEvent mouseEvent, const MouseData& mouseData) override {}

	// Non virtual as may not want to implement - gets a lot of calls 
	void OnMouseMove(const MouseData& mouseData) override {};

	// Called when HAPI Sprites detects a controller event - optional
	void OnControllerEvent(unsigned int controllerId, EControllerEvent controllerEvent, unsigned int buttonIndex,
		const ControllerData& controllerData) override {}

	// Called with interpreted key presses into character entry
	void OnTextEntered(char enteredText) override {}
*/
};

