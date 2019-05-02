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
	void spawn(VectorF direction, VectorF TowerPosition);
	void render(int &yOffset);
	void move();
	void setSize(VectorF size) { sprite->GetTransformComp().SetScaling({ size });; };
	void Collision(std::vector<EnemyAI> & enemys, int & yOffset);
	void Update(std::vector<EnemyAI> & enemies, int & yOffset);
	const bool isSpawned() { return m_Spawned; };
	int damage{ 5 };
private:
	VectorF m_Projectile_Position;
	VectorF m_Projectile_Direction;
	std::shared_ptr<Sprite> sprite = HAPI_Sprites.MakeSprite("Data\\Projectiles\\Paintball.png");
	bool m_Spawned{ false };
	int m_speed{ 5 };
	
};

