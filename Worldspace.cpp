#include "Worldspace.h"
#include "UserInterface.h"
#include <HAPISprites_Lib.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "UserInterface.h"

using namespace HAPI_UI_SPACE;
using namespace HAPISPACE;
using namespace std;


Worldspace::Worldspace()
{
	
}


Worldspace::~Worldspace()
{
	
}


void Worldspace::Game()
{	
	UserInterface Menu;
			
	std::shared_ptr<Sprite> sprite = HAPI_Sprites.MakeSprite("Data\\tower.png", 1);
	int scrollValue = 0;

	if (!sprite)
	{
		HAPI_Sprites.UserMessage("Error, WILL NOT Load Mate... Just Terminate.", "ERROR");
		return;
	}
	
	int test = 0;
	xp.difficulty(1);
	while (HAPI_Sprites.Update())
	{
		
		SCREEN_SURFACE->Clear();
		
		//HAPI_Sprites.RenderText(VectorI(j * 32, i * 40), Colour255::MAGENTA, std::to_string(*pointer), 20);

		const HAPISPACE::HAPI_TMouseData &mousedata = HAPI_Sprites.GetMouseData();
		scrollValue -= mousedata.wheelMovement / 3;

		Menu.Map_Pointer->RenderMap(scrollValue);

		//sprite->Render(SCREEN_SURFACE);

		//test render for Level
		HAPI_Sprites.RenderText(VectorI(1, 10), Colour255::RED, "Level: ", 40);
		HAPI_Sprites.RenderText(VectorI(120, 10), Colour255::RED, std::to_string(xp.getLevel()), 40);

		//test render for xp
		HAPI_Sprites.RenderText(VectorI(1, 50), Colour255::RED, "XP: ", 40);
		HAPI_Sprites.RenderText(VectorI(80, 50), Colour255::RED, std::to_string(xp.getXp()), 40);
		
		//test render for currency
		HAPI_Sprites.RenderText(VectorI(1, 90), Colour255::RED, "Currency: ", 40);
		HAPI_Sprites.RenderText(VectorI(190, 90), Colour255::RED, std::to_string(xp.getCurrency()), 40);
		
		const MouseData& mouse{ HAPI_Sprites.GetMouseData() };

		xp.updateXp();

		Menu.MainMenuUI();
			
	}

	

	if (!HAPI_Sprites.Update())
	{
		SaveFile();
	}


}

void Worldspace::Initialise()
{
// Loading data before game starts
	ConfigLoad();
	LoadFile();
	if (!HAPI_Sprites.Initialise(m_width, m_height, "Crystal Cove - Error, Game name undefined", eHSEnableUI))
	{
		return;
	}
	Game();
}

HAPISPACE::VectorI Worldspace::GetScreenSize()
{
	return HAPISPACE::VectorI(m_width, m_height);
}

void Worldspace::ConfigLoad()
{
	std::ifstream Config;
	Config.open("Config.txt");
	if (Config.fail())
	{
		HAPI_Sprites.UserMessage("Config Missing", "ERROR");
	}

	std::string name;
	int input;


	while (Config >> name >> input)
	{
		if (name == "Screenwidth")
		{
			m_width = input;
		}
		if (name == "Screenheight")
		{
			m_height = input;
		}		
	}

	Config.close();
}

void Worldspace::SaveFile()
{
	ofstream SaveFile;
	SaveFile.open("Save.txt");
	if (SaveFile.fail())
	{
		HAPI_Sprites.UserMessage("Save File bugged", "ERROR");
	}

	int PlayerXp = xp.getXp();
	int Level = xp.getLevel();
	int currency = xp.getCurrency();

	SaveFile << "PlayerXp: " << PlayerXp << std::endl;
	SaveFile << "Level: " << Level << std::endl;
	SaveFile << "Currency: " << currency << std::endl;
	SaveFile << "Difficulty: " << m_difficulty << std::endl;
	SaveFile.close();
}

void Worldspace::LoadFile()
{
	std::ifstream Load;
	Load.open("Save.txt");
	if (Load.fail())
	{
		HAPI_Sprites.UserMessage("Failed To Load Your Save", "ERROR");
	}

	std::string name;
	int input;
	
	while (Load >> name >> input)
	{
		if (name == "PlayerXP:")
		{
			xp.setXp(input);
		}
		if (name == "Level:")
		{
			xp.setLevel(input);
		}
		if (name == "Currency:")
		{
			xp.setCurrency(input);
		}
		if (name == "Difficulty:")
		{
			m_difficulty = input;
		}
	}
	Load.close();
}

void Worldspace::ResetFile()
{
	ofstream SaveFile;
	SaveFile.open("Save.txt");
	if (SaveFile.fail())
	{
		HAPI_Sprites.UserMessage("Save File bugged", "ERROR");
	}

	int a = 0;
	int b = 1;

	xp.setCurrency(a);
	xp.setLevel(b);
	xp.setXp(a);

	SaveFile << "PlayerXp: " << a << std::endl;
	SaveFile << "Level: " << b << std::endl;
	SaveFile << "Currency: " << a << std::endl;
	SaveFile << "Difficulty: " << m_difficulty << std::endl;
	SaveFile.close();
}
