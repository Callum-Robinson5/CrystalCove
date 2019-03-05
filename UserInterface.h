#pragma once
#include <HAPISprites_Lib.h>

#include <HAPISprites_UI.h>
#include <iostream>
#include "Map.h"
#include "XP.h"

using namespace HAPI_UI_SPACE;


class UserInterface : public IHapiSpritesUIListener
{
public:
	UserInterface();
	~UserInterface();

	

	bool run();


	class XP m_xp;
	class Map map;
	//void UI_ButtonPressed(UIWindow& window, const std::string& buttonName, int* userId = nullptr) override;
	void UI_RadioButtonChangeState(UIWindow& window, const std::string& buttonName, bool pressed, int* userId = nullptr) override;

};

