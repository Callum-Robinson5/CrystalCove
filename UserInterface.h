#pragma once
#include <HAPISprites_Lib.h>
#include <HAPISprites_UI.h>
#include <iostream>


using namespace HAPI_UI_SPACE;

class Map;
class XP;

class UserInterface : public IHapiSpritesUIListener
{
public:
	UserInterface();
	~UserInterface();

	bool run();
	Map *Map_Pointer{ nullptr }; //declared pointer towards the class

	//void UI_ButtonPressed(UIWindow& window, const std::string& buttonName, int* userId = nullptr) override;
	void UI_RadioButtonChangeState(UIWindow& window, const std::string& buttonName, bool pressed, int* userId = nullptr) override;

};

