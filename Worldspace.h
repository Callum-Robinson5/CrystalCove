#pragma once
#include "XP.h"
#include "Map.h"
#include "EnemyAI.h"
#include "TowerAI.h"
#include "Projectiles.h"


#include <HAPISprites_Lib.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace HAPI_UI_SPACE;
using namespace HAPISPACE;
using namespace std;

class Worldspace //: IHapiSpritesInputListener


{ 
public:
	Worldspace();
	~Worldspace();
	void Initialise();
	const VectorI GetScreenSize() { return m_ScreenSize; };

	std::vector<EnemyAI> GetEnemies() { return Enemies; };

	void SpawnWave(int numEnemies, int distanceBetweenEnemies);
	void PlaceTower(VectorF position, Map & map, std::vector<TowerAI> & towers);


	void ResetFile();

private:
	int m_width{ 1280 };
	int m_height{ 800 };
	VectorI m_ScreenSize{ 1280,800 };
	int m_difficulty{ 1 };
	int scrollValue{ 0 };

	int maxEnemies{ 50 };
	int maxTowers{ 50 };
	int maxProjectiles{ 100 };


	std::vector<EnemyAI> Enemies;
	std::vector<TowerAI> m_Towers;
	std::vector<Projectiles> m_Projectiles;
	
	class XP xp;
	void Game();
	
	void ConfigLoad();
	void SaveFile();
	void LoadFile();

};

