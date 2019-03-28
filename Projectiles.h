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
	void Collision(std::vector<EnemyAI> & enemys, int & yOffset);
	void Update(std::vector<EnemyAI> & enemies, int & yOffset);
	const bool isSpawned() { return m_Spawned; };
private:
	VectorF m_Projectile_Position;
	VectorF m_Projectile_Direction;
	std::shared_ptr<Sprite> sprite = HAPI_Sprites.MakeSprite("Data\\Projectiles\\Paintball");
	bool m_Spawned{ false };
	int m_speed{ 5 };
};

