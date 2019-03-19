#pragma once
#include <HAPISprites_Lib.h>
#include "EnemyAI.h"
using namespace HAPISPACE;
class TowerAI
{
public:
	TowerAI();
	~TowerAI();
public:
	void spawn(int &yOffset);
	void render(int &yOffset);
	void getTowerPosition(VectorF);
	void towerLOS(std::vector<EnemyAI> Enemies);
private:
	VectorF m_Tower_Position;
	std::shared_ptr<Sprite> sprite = HAPI_Sprites.MakeSprite("Data\\tower.png");
	bool m_Spawned{ false };
};

