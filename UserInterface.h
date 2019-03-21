#pragma once
#include <HAPISprites_Lib.h>
#include <HAPISprites_UI.h>
#include <iostream>
#include "TowerAI.h"


using namespace HAPI_UI_SPACE;

class Map;
class Worldspace;



class UserInterface : public IHapiSpritesUIListener
{
public:
	UserInterface();
	~UserInterface();
	void MainMenuUI();
	void GameUI();
	Map *Map_Pointer{ nullptr }; //declared pointer towards the Map class
	Worldspace *world{ nullptr }; //declared pointer towards the worldspace class
	class TowerAI tower_AI;
	bool loadMenu = true;
	bool loadgameUi = false;
	int yoff = 1;
	bool tower1 = false;
	

private:
	
//	void UI_ButtonPressed(UIWindow& window, const std::string& buttonName, int* userId = nullptr) override;
	void UI_RadioButtonChangeState(UIWindow& window, const std::string& buttonName, bool pressed, int* userId = nullptr) override;

};

