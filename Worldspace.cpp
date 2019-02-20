#include "Worldspace.h"
#include <HAPISprites_Lib.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>



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

	std::shared_ptr<Sprite> sprite = HAPI_Sprites.MakeSprite("Data\\tower.png", 1);

	if (!sprite)
	{
		HAPI_Sprites.UserMessage("Error, WILL NOT Load Mate... Just Terminate.", "ERROR");
		return;
	}
	
	float i = 50.0f;
	while (HAPI_Sprites.Update())
	{
		i += 5.0f;
		
		SCREEN_SURFACE->Clear();

		sprite->GetTransformComp().SetPosition({ 200,200 });
		sprite->GetTransformComp().SetScaling({ 0.3f, 0.3f });
		sprite->GetTransformComp().SetRotation(i);

		sprite->Render(SCREEN_SURFACE);

		const MouseData& mouse{ HAPI_Sprites.GetMouseData() };
		xp.updateXp();


		if (mouse.leftButtonDown)
		{
			xp.addXp(100);
			//SaveFile();
			std::cout << "Saves" << std::endl;
		}

		if (mouse.rightButtonDown)
		{
			ResetFile();
			std::cout << "Reset" << std::endl;
		}
	}

	if (!HAPI_Sprites.Update())
	{
		SaveFile();
		std::cout << "test save" << endl;
	}


}

void Worldspace::Initialise()
{
// Loading data before game starts
	ConfigLoad();
	LoadFile();
	if (!HAPI_Sprites.Initialise(m_width, m_height, "Crystal Cove - Error, Game name undefined"))
	{
		return;
	}
	
	Game();
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
		std::cout << input << endl;
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
