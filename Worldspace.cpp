#include "Worldspace.h"
#include "UserInterface.h"
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
	UserInterface UserInt;


	Map Maptest;


	for (int i{ 0 }; i < maxTowers; i++)
	{
		m_Towers.push_back(TowerAI());
	}

	for (int i{ 0 }; i < maxProjectiles; i++)
	{
		m_Projectiles.push_back(Projectiles());
	}

	for (int i{ 0 }; i < maxEnemies; i++)
	{
		Enemies.push_back(EnemyAI());
	}

	float i = 50.0f;
	xp.difficulty(1);


	while (HAPI_Sprites.Update())
	{
		i += 5.0f;


		if (UserInt.enabledGen == true)
		{
			Maptest.GeneratePath(m_difficulty);
			UserInt.enabledGen = false;
			xpON = true;
		}


		SCREEN_SURFACE->Clear();


		//HAPI_Sprites.RenderText(VectorI(j * 32, i * 40), Colour255::MAGENTA, std::to_string(*pointer), 20);
		const HAPISPACE::HAPI_TMouseData &mouseData = HAPI_Sprites.GetMouseData();
		scrollValue -= mouseData.wheelMovement / 3;
		//sprite->Render(SCREEN_SURFACE);
		Maptest.RenderMap(scrollValue);


		for (auto & enemy : Enemies)
		{
			enemy.update(scrollValue, Maptest.GetPath());
		}

		for (auto & projectile : m_Projectiles)
		{
			if (projectile.isSpawned())
			{
				projectile.Update(Enemies, scrollValue);
			}
		}

		for (auto & tower : m_Towers)
		{
			tower.render(scrollValue);
			tower.search(Enemies, m_Projectiles);
		}

		if (xpON == true)
		{
			//test render for Level
			HAPI_Sprites.RenderText(VectorI(1, 10), Colour255::RED, "Level: ", 40);
			HAPI_Sprites.RenderText(VectorI(120, 10), Colour255::RED, std::to_string(xp.getLevel()), 40);

			//test render for xp
			HAPI_Sprites.RenderText(VectorI(1, 50), Colour255::RED, "XP: ", 40);
			HAPI_Sprites.RenderText(VectorI(80, 50), Colour255::RED, std::to_string(xp.getXp()), 40);

			//test render for currency
			HAPI_Sprites.RenderText(VectorI(1, 90), Colour255::RED, "Currency: ", 40);
			HAPI_Sprites.RenderText(VectorI(190, 90), Colour255::RED, std::to_string(xp.getCurrency()), 40);
		}

		if (UserInt.infMoney == true)
		{
			xp.addCurrency(1000);
			UserInt.infMoney = false;
		}
		if (UserInt.infXP == true)
		{
			xp.addXp(1000);
			UserInt.infXP = false;
		}
		if (UserInt.reset == true)
		{
			ResetFile();
			UserInt.reset = false;
		}

		const MouseData& mouse{ HAPI_Sprites.GetMouseData() };

		xp.updateXp();

		if (mouse.rightButtonDown)
		{

			if (UserInt.enabledTower1 == true)
			{
				PlaceTower(VectorF(mouse.x, mouse.y), Maptest, m_Towers);
				std::cout << "test" << std::endl;
			}

		}
		if (UserInt.nextWave == true)
		{
			SpawnWave(numEnemiesInWave, 70);
			UserInt.nextWave = false;
		}

		UserInt.MainMenuUI();
		UserInt.GameUI();

	}

	if (!HAPI_Sprites.Update())
	{
		SaveFile();
		std::cout << "test save" << endl;
	}



}

void Worldspace::SpawnWave(int& numEnemies, int distanceBetweenEnemies)
{
	bool allDead = true;

	for (int i{ 0 };i<maxEnemies; i++)
	{
		if (Enemies[i].isAlive())
		{
			allDead = false;
			break;
		}
	}
	
	if (allDead)
	{
		if (waveNumber % 5 != 0)
		{
			if (waveNumber == 1)
			{
				avaliableEnemies.push_back('G');
			}
			else if (waveNumber == 6)
			{
				avaliableEnemies.push_back('g');
			}
			else if (waveNumber == 11)
			{
				avaliableEnemies.push_back('s');
			}


			for (int i{ 0 }; i < numEnemies; i++)
			{
				Enemies[i].spawn(&xp, avaliableEnemies[rand() % avaliableEnemies.size()], -(i*distanceBetweenEnemies));
			}
		}
		else
		{
			for (int i{ 0 }; i < waveNumber / 5; i++)
			{
				Enemies[i].spawn(&xp, 'S', -(i*distanceBetweenEnemies));
			}
		}
		if (numEnemies < maxEnemies)
		{
			numEnemiesInWave += rand() & 6;
			if (numEnemies > maxEnemies)
			{
				numEnemies = maxEnemies;
			}
		}
		waveNumber++;

	}
}

void Worldspace::PlaceTower(VectorF position, Map & map, vector<TowerAI> & towers)
{
	if (xp.getCurrency() >= 100)
	{
		bool canSpawn = true;
		for (auto & tile : map.GetPath())
		{
			if (position.x + 90 < tile.x || position.x > tile.x + 90
				|| position.y + 90 < tile.y - scrollValue || position.y > tile.y - scrollValue + 90)
			{
			}
			else
			{
				canSpawn = false;
			}
		}
		for (auto & tower : towers)
		{
			if (position.x + 80 < tower.getTowerPosition().x || position.x > tower.getTowerPosition().x + 80
				|| position.y + 80 < tower.getTowerPosition().y - scrollValue || position.y > tower.getTowerPosition().y - scrollValue + 80)
			{
			}
			else
			{
				canSpawn = false;
			}
		}
		if (position.x < 40 || position.x > 951)
		{
			canSpawn = false;
		}
		if (canSpawn)
		{
			for (auto & tower : m_Towers)
			{
				if (!tower.isSpawned())
				{
					tower.spawn(scrollValue);
					xp.addCurrency(-100);
					break;
				}
			}
		}
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
