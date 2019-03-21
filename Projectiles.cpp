#include "Projectiles.h"
#include <HAPISprites_Lib.h>
#include "TowerAI.h"
using namespace HAPISPACE;



Projectiles::Projectiles()
{
}


Projectiles::~Projectiles()
{
}

void Projectiles::spawn(int &yOffset, VectorF TowerPosition)
{
	const HAPISPACE::MouseData &mouseData = HAPI_Sprites.GetMouseData();

	if (!sprite)
	{
		HAPI_Sprites.UserMessage("Could not load spritesheet", "Error");
		return;
	}

	float x = mouseData.x;
	float y = mouseData.y;
	m_Projectile_Position = { TowerPosition.x, TowerPosition.y + yOffset };
	sprite->GetTransformComp().SetScaling({ 0.3f, 0.3f });
	sprite->GetTransformComp().SetRotation(0.0f);
	m_Spawned = true;

}

void Projectiles::render(int &yOffset)
{

	if (m_Spawned)
	{
		sprite->GetTransformComp().SetPosition(VectorF(m_Projectile_Position.x, m_Projectile_Position.y - yOffset)); //needs to start at towers position so change this later
		sprite->Render(SCREEN_SURFACE);
		m_Rendered = true;
	}
}

void Projectiles::shoot(int &Offest, std::vector<EnemyAI> Enemies)
{
	if (m_Rendered)
	{
		
	}
}

/*todo: make projectiles shoot towards enemy
projectiles deal damage
projetiles stop and die when hitting enemy
*/