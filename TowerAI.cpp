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

void TowerAI::towerLOS(std::vector<EnemyAI> Enemies, std::vector<Projectiles>& projectiles) //creates projectile, need to change so there ant crazy ammount of projectiles
{
	int scrollValue = 0;
	const HAPISPACE::MouseData &mouseData = HAPI_Sprites.GetMouseData();
	scrollValue -= mouseData.wheelMovement / 3;
	for (auto & enemy : Enemies)
	{
		if (fireRate <= 0)
		{
			if (m_Tower_Position.DistanceBetween(enemy.getPosition()) <= 200)
			{
				Projectiles newProjectile;
				newProjectile.spawn(scrollValue, enemy, m_Tower_Position);
				projectiles.push_back(newProjectile);
				//testProjectiles.shoot(scrollValue, Enemies, m_Tower_Position);
				fireRate = 100;
				break;
			}
		}
	}
	fireRate--;
}