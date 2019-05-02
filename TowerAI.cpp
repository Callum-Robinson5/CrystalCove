#include "TowerAI.h"
#include "EnemyAI.h"
#include "Projectiles.h"
#include <math.h>
#include <HAPISprites_Lib.h>
using namespace HAPISPACE;

TowerAI::TowerAI()
{
}


TowerAI::~TowerAI()
{
}





void TowerAI::spawn(std::vector<EnemyAI> Enemies, std::vector<Projectiles>& projectiles, char type, int &yOffset)
{
	
	const HAPISPACE::MouseData &mouseData = HAPI_Sprites.GetMouseData();

	if (!sprite)
				{
					HAPI_Sprites.UserMessage("Could not load spritesheet", "Error");
					return;
				}

	for (auto & enemy : Enemies)
		for (auto & projectile : projectiles)
		{
			{
				switch (type) ///different settings for each tower
				{
				case 'T':
					 sprite = HAPI_Sprites.MakeSprite("Data\\Towers/Paint Thrower.png");
					fireRate = 200;
					enemy.takeDamage(2);
					break;
				case 't':
					sprite = HAPI_Sprites.MakeSprite("Data\\Towers/Paint Slinger.png");
					fireRate = 600;
					enemy.takeDamage(2);
					break;
				case 'P':
					sprite = HAPI_Sprites.MakeSprite("Data\\Towers/Paintadier.png");
					fireRate = 400;
					enemy.takeDamage(5);
					break;
				case 'p':
					sprite = HAPI_Sprites.MakeSprite("Data\\Towers/Painttillary.png");
					fireRate = 700;
					enemy.takeDamage(10);
					projectile.setSize(0.7f);

					break;
				}
			}
		}

	float x = mouseData.x;
	float y = mouseData.y;
	m_Tower_Position = { (float)mouseData.x, (float)mouseData.y + yOffset};
	sprite->GetTransformComp().SetOrigin(VectorF(50, 50));
	sprite->GetTransformComp().SetRotation(0.0f);
	m_Spawned = true;

}

void TowerAI::render(int &yOffset) //renders the tower and sets its position
{
	if (m_Spawned)
	{
		sprite->GetTransformComp().SetPosition(VectorF(m_Tower_Position.x, m_Tower_Position.y - yOffset));
		sprite->Render(SCREEN_SURFACE);
	}
}

void TowerAI::search(std::vector<EnemyAI> Enemies, std::vector<Projectiles>& projectiles)
{
	for (auto & enemy : Enemies)
	{
		if (enemy.isAlive())
		{
			if (m_Tower_Position.DistanceBetween(enemy.getPosition()) <= m_Range)
			{
				VectorF direction = enemy.getPosition() - m_Tower_Position;
				direction = direction.Normalized();
				float radians = atan2(direction.y, direction.x);
				sprite->GetTransformComp().SetRotation(radians + M_PI / 2);

				if (coolDown <= 0)
				{
					fire(direction, projectiles);
					coolDown = fireRate;
				}
				break;
			}
		}
	}
	coolDown--;
}

void TowerAI::fire(VectorF direction, std::vector<Projectiles>& projectiles)
{
	for (auto &projectile: projectiles)
	{
		if (!projectile.isSpawned())
		{
			projectile.spawn(direction, m_Tower_Position);
			break;
		}
	}
}


