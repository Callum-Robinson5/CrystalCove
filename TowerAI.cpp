#include "TowerAI.h"
#include "EnemyAI.h"
#include "Projectiles.h"
#include <HAPISprites_Lib.h>
using namespace HAPISPACE;

TowerAI::TowerAI()
{
}


TowerAI::~TowerAI()
{
}

void TowerAI::spawn(int &yOffset)
{
	const HAPISPACE::MouseData &mouseData = HAPI_Sprites.GetMouseData();
	
	if (!sprite)
	{
		HAPI_Sprites.UserMessage("Could not load spritesheet", "Error");
		return;
	}

	float x = mouseData.x;
	float y = mouseData.y;
	m_Tower_Position = { (float)mouseData.x, (float)mouseData.y + yOffset};
	sprite->GetTransformComp().SetScaling({ 0.3f, 0.3f });
	sprite->GetTransformComp().SetRotation(0.0f);
	m_Spawned = true;

}

void TowerAI::render(int &yOffset)
{
	if (m_Spawned)
	{
		sprite->GetTransformComp().SetPosition(VectorF(m_Tower_Position.x, m_Tower_Position.y - yOffset));
		sprite->Render(SCREEN_SURFACE);
	}
}

void TowerAI::getTowerPosition(VectorF)
{
	//return m_Tower_Position;
}


void TowerAI::towerLOS(std::vector<EnemyAI> Enemies) //creates projectile, need to change so there ant crazy ammount of projectiles
{
	int scrollValue = 0;
	const HAPISPACE::MouseData &mouseData = HAPI_Sprites.GetMouseData();
	scrollValue -= mouseData.wheelMovement / 3;
	for (auto & enemy : Enemies)
	{
		if (m_Tower_Position.DistanceBetween(enemy.getPosition()) <= 200)
		{
			Projectiles testProjectiles;

			testProjectiles.spawn(scrollValue, m_Tower_Position);
			testProjectiles.render(scrollValue);
			//shoot projectile
		}
	}
}