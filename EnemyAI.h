#pragma once
#include <HAPISprites_Lib.h>
#include "XP.h"

using namespace HAPISPACE;
class EnemyAI
{
public:
	EnemyAI();
	virtual ~EnemyAI();

	void spawn(XP* xp, char type, int yPos);
	void render(int &yOffset);
	void move(const std::vector<HAPISPACE::VectorF> &path);
	void die();
	bool isAlive();
	void takeDamage(int Damage) { if(m_Alive)enemy_health -= Damage; };
	void update(int &yOffset, const std::vector<HAPISPACE::VectorF> &path);

	const std::shared_ptr<Sprite> getSprite() { return sprite; };
	const VectorF getPosition() { return m_Position; };
	const int getHealth() { return enemy_health; };

private:
	int m_Checkpoint = 0;
	int m_speed{ 5 };
	VectorF m_Position;
	std::shared_ptr<Sprite> sprite = HAPI_Sprites.MakeSprite("Data\\Enemy/Golem.png");
	int enemy_health{10};
	bool m_Alive{ false };
	bool m_Died{ true };
	XP* m_Xp;
};

