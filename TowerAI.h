#pragma once
#include <HAPISprites_Lib.h>
#include "EnemyAI.h"
#include "Projectiles.h"
using namespace HAPISPACE;
class Projectiles;

class TowerAI
{
public:
	TowerAI();
	~TowerAI();
public:
	void spawn(int &yOffset);
	void render(int &yOffset);
	void search(std::vector<EnemyAI> Enemies, std::vector<Projectiles>& projectiles);
	const VectorF getTowerPosition() { return m_Tower_Position; };
	const bool isSpawned() { return m_Spawned; };

private:

	void fire(VectorF direction, std::vector<Projectiles>& projectiles);

	VectorF m_Tower_Position;
	int m_Range{ 300 };
	int coolDown{ 10 };
	int fireRate{ 100 };

	std::shared_ptr<Sprite> sprite = HAPI_Sprites.MakeSprite("Data\\Towers/Paint Thrower.png");
	bool m_Spawned{ false };
	
};

