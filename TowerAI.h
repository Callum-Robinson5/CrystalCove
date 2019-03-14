#pragma once
#include <HAPISprites_Lib.h>
using namespace HAPISPACE;
class TowerAI
{
public:
	TowerAI();
	~TowerAI();
public:
	void spawn(int &yOffset);
	void render(int &yOffset);
private:
	VectorF m_Position;
	std::shared_ptr<Sprite> sprite = HAPI_Sprites.MakeSprite("Data\\tower.png");
	bool m_Spawned{ false };
};

