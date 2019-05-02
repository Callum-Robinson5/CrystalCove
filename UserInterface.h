#pragma once
#include <HAPISprites_Lib.h>
#include <HAPISprites_UI.h>
#include <iostream>
#define Nathan bool
#define And bool
#define Callum bool
#define elephantRidingATree bool




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
	Worldspace *World_Pointer{ nullptr }; //declared pointer towards the worldspace class
//	TowerAI *Tower_Pointer{ nullptr }; //declared pointer towards the tower class
	bool loadMenu = true;
	bool loadgameUi = false;
	bool test = true;
	bool test1 = true;

	

	Nathan enabledTower1{ false };
	And enabledTower2{ false };
	Callum enabledTower3{ false };
	elephantRidingATree enabledTower4{ false };
	elephantRidingATree enabledTower5{ false };
	elephantRidingATree nextWave{ false };
	elephantRidingATree enabledGen{ false };
	elephantRidingATree infMoney{ false };
	elephantRidingATree infXP{ false };
	elephantRidingATree reset{ false };
	elephantRidingATree x2{ false };

private:
	
//	void UI_ButtonPressed(UIWindow& window, const std::string& buttonName, int* userId = nullptr) override;
	void UI_RadioButtonChangeState(UIWindow& window, const std::string& buttonName, bool pressed, int* userId = nullptr) override;

};

