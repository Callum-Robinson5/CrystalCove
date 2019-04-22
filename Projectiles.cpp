#include "Projectiles.h"
#include <HAPISprites_Lib.h>
using namespace HAPISPACE;



Projectiles::Projectiles()
{
}


Projectiles::~Projectiles()
{
}

void Projectiles::spawn(VectorF direction, VectorF TowerPosition)
{
	int scrollValue = 0;
	const HAPISPACE::MouseData &mouseData = HAPI_Sprites.GetMouseData();
	scrollValue -= mouseData.wheelMovement / 3;

	if (!sprite)
	{
		HAPI_Sprites.UserMessage("Could not load spritesheet", "Error");
		return;
	}

	m_Projectile_Position = { TowerPosition.x, TowerPosition.y + scrollValue };
	m_Projectile_Direction = direction;
	sprite->GetTransformComp().SetScaling({ 0.3f, 0.3f });
	sprite->GetTransformComp().SetRotation(0.0f);
	m_Spawned = true;

}

void Projectiles::render(int &yOffset)
{
	
		if (m_Spawned)
		{
			sprite->GetTransformComp().SetPosition(VectorF(m_Projectile_Position.x, m_Projectile_Position.y - yOffset));// += 10 * m_speed);
			sprite->Render(SCREEN_SURFACE);

		}
}


void Projectiles::move()
{
		m_Projectile_Position += m_Projectile_Direction * m_speed;
		sprite->GetTransformComp().SetPosition(m_Projectile_Position);
		if (m_Projectile_Position.x < -10 || m_Projectile_Position.x > 1280 || m_Projectile_Position.y < -10 || m_Projectile_Position.y > 3000)
		{
			m_Spawned = false;
		}
}

void Projectiles::Collision(std::vector<EnemyAI> & enemies, int & yOffset)
{
	for (auto &enemy : enemies)
	{
		if (enemy.isAlive() && m_Spawned)
		{
			enemy.getSprite()->GetTransformComp().SetPosition({ enemy.getSprite()->GetTransformComp().GetPosition().x, enemy.getSprite()->GetTransformComp().GetPosition().y + yOffset });
			if (sprite->CheckCollision(*(enemy.getSprite())))
			{
				enemy.takeDamage(5);
				if (enemy.getHealth() <= 0)
					enemy.die();
				m_Spawned = false;
				enemy.getSprite()->GetTransformComp().SetPosition({ enemy.getSprite()->GetTransformComp().GetPosition().x, enemy.getSprite()->GetTransformComp().GetPosition().y - yOffset });
				break;
			}
			enemy.getSprite()->GetTransformComp().SetPosition({ enemy.getSprite()->GetTransformComp().GetPosition().x, enemy.getSprite()->GetTransformComp().GetPosition().y - yOffset });
		}
	}
}

void Projectiles::Update(std::vector<EnemyAI> & enemies, int & yOffset)
{
	if (isSpawned())
	{
		move();
		Collision(enemies, yOffset);
		render(yOffset);
	}

}



/*
projectiles deal damage
projetiles stop and die when hitting enemy
*/