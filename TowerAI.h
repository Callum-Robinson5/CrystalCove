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
	const VectorF getTowerPosition() { return m_Tower_Position; };
	void towerLOS(std::vector<EnemyAI> Enemies, std::vector<Projectiles>& projectiles);
	const bool isSpawned() { return m_Spawned; };

private:
	VectorF m_Tower_Position;
	int fireRate{ 10 };
	std::shared_ptr<Sprite> sprite = HAPI_Sprites.MakeSprite("Data\\Towers/Paint Thrower.png");
	bool m_Spawned{ false };
};

