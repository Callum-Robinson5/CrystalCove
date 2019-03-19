#pragma once
#include <HAPISprites_Lib.h>
#include "TowerAI.h"
#include "EnemyAI.h"
using namespace HAPISPACE;
class Projectiles
{
public:
	Projectiles();
	~Projectiles();
public:
	void spawn(int &yOffset, VectorF TowerPosition);
	void render(int &yOffset);
	void shoot(int &Offest, std::vector<EnemyAI> Enemies);
private:
	VectorF m_Projectile_Position;
	std::shared_ptr<Sprite> sprite = HAPI_Sprites.MakeSprite("Data\\Turret.png");
	bool m_Spawned{ false };
	bool m_Rendered{ false };
	int m_speed{ 10 };
};

