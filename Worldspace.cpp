#include "Worldspace.h"
#include <HAPISprites_Lib.h>
#include <stdlib.h>
#include <fstream>

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
	// We must initialise HAPI Sprites before doing anything with it
	// This call allows us to specify the screen size and optionally the window title text and flags

	std::shared_ptr<Sprite> sprite = HAPI_Sprites.MakeSprite("Data\\tower.png", 1);

	if (!sprite)
	{
		HAPI_Sprites.UserMessage("Error, WILL NOT Load Mate... Just Terminate.", "ERROR");
		return;
	}
	float i = 50.0f;
	while (HAPI_Sprites.Update())
	{
		i += 60.0f;

		SCREEN_SURFACE->Clear();

		sprite->GetTransformComp().SetPosition({ 200,200 });
		sprite->GetTransformComp().SetScaling({ 0.3f, 0.3f });
		sprite->GetTransformComp().SetRotation(i);

		sprite->Render(SCREEN_SURFACE);
	}

}

void Worldspace::Initialise()
{
// Loading data before game starts
	Createfile();
	if (!HAPI_Sprites.Initialise(m_width, m_height, "Crystal Cove - Error, Game name undefined"))
	{
		return;
	}
	Game();
}

void Worldspace::Createfile()
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
		if (name == "Difficulty")
		{
			m_difficulty = input;
		}
		
	}
}

