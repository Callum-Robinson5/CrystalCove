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
	void spawn(int &yOffset, EnemyAI& Enemy, VectorF TowerPosition);
	void render(int &yOffset);
	void move();
	void shoot(int &Offest, std::vector<EnemyAI> Enemies, VectorF TowerPosition);
private:
	VectorF m_Projectile_Position;
	VectorF m_Projectile_Direction;
	std::shared_ptr<Sprite> sprite = HAPI_Sprites.MakeSprite("Data\\Paintball.png");
	bool m_Spawned{ false };
	bool m_Rendered{ false };
	int m_speed{ 5 };
};

