#include "Projectiles.h"
#include <HAPISprites_Lib.h>
using namespace HAPISPACE;



Projectiles::Projectiles()
{
}


Projectiles::~Projectiles()
{
}

void Projectiles::spawn(int &yOffset, EnemyAI& Enemy, VectorF TowerPosition)
{

	if (!sprite)
	{
		HAPI_Sprites.UserMessage("Could not load spritesheet", "Error");
		return;
	}

	m_Projectile_Position = { TowerPosition.x, TowerPosition.y + yOffset };
	m_Projectile_Direction = VectorF(Enemy.getPosition() - TowerPosition).Normalized();
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
			m_Rendered = true;

		}
}


void Projectiles::move()
{
	if (m_Rendered = true)
	{
		m_Projectile_Position += m_Projectile_Direction * m_speed;
		sprite->GetTransformComp().SetPosition(m_Projectile_Position);
	}
}



/*
projectiles deal damage
projetiles stop and die when hitting enemy
*/