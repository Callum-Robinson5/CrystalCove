#pragma once
#include <HAPISprites_Lib.h>
using namespace HAPISPACE;
class EnemyAI
{
public:
	EnemyAI();
	virtual ~EnemyAI();

	void spawn();
	void render(int &yOffset);
	void move(const std::vector<HAPISPACE::VectorF> &path);
	void health();
	void update();

private:
	int width{ 1280 };
	int height{ 800 };
	int m_Checkpoint{ 0 };
	int m_speed{ 10 };
	VectorF m_Position = VectorF({16*40,-50});
	std::shared_ptr<Sprite> sprite = HAPI_Sprites.LoadSprite("Data\\Troll2.xml");
	int enemy_health;
};

