#pragma once
#include <HAPISprites_Lib.h>
#include "XP.h"

using namespace HAPISPACE;
class EnemyAI
{
public:
	EnemyAI();
	virtual ~EnemyAI();

	void spawn(XP* xp, int yPos);
	void render(int &yOffset);
	void move(const std::vector<HAPISPACE::VectorF> &path);
	void die();
	bool isAlive();
	void update(int &yOffset, const std::vector<HAPISPACE::VectorF> &path);

	const VectorF getPosition() { return m_Position; };

private:
	int m_Checkpoint = 0;
	int m_speed{ 10 };
	VectorF m_Position;
	std::shared_ptr<Sprite> sprite = HAPI_Sprites.LoadSprite("Data\\Troll2.xml");
	int enemy_health{10};
	bool m_Alive{ false };
	bool m_Died{ false };
	XP* m_Xp;
};

