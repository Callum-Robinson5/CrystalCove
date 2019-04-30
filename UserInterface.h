#pragma once
#include <HAPISprites_Lib.h>
#include <HAPISprites_UI.h>
#include <iostream>



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

	bool enabledTower1{ false };
	bool enabledTower2{ false };
	bool enabledTower3{ false };
	bool enabledTower4{ false };
	bool enabledTower5{ false };
	bool nextWave{ false };
	bool enabledGen{ false };

private:
	
//	void UI_ButtonPressed(UIWindow& window, const std::string& buttonName, int* userId = nullptr) override;
	void UI_RadioButtonChangeState(UIWindow& window, const std::string& buttonName, bool pressed, int* userId = nullptr) override;

};

