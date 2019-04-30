#include "EnemyAI.h"
#include <HAPISprites_Lib.h>
using namespace HAPISPACE;

EnemyAI::EnemyAI()
{
}

EnemyAI::~EnemyAI()
{
}


void EnemyAI::spawn(XP* xp, char type, int yPos = 0)
{
	if (!sprite)
	{
		HAPI_Sprites.UserMessage("Could not load spritesheet", "Error");
		return;
	}


	switch (type)
	{
	case 'G':
		sprite = HAPI_Sprites.MakeSprite("Data\\Enemy/Golem.png");
		enemy_health = 20;
		m_speed = 5;
		sprite->GetTransformComp().SetScaling(VectorF(1, 1));
		break;
	case 'g':
		sprite = HAPI_Sprites.MakeSprite("Data\\Enemy/Goblin.png");
		enemy_health = 10;
		m_speed = 10;
		sprite->GetTransformComp().SetScaling(VectorF(1, 1));
		break;
	case 's':
		sprite = HAPI_Sprites.MakeSprite("Data\\Enemy/Shrek_the_Snek.png");
		enemy_health = 15;
		m_speed = 10;
		sprite->GetTransformComp().SetScaling(VectorF(0.7, 0.7));
		break;
	case 'S':
		sprite = HAPI_Sprites.MakeSprite("Data\\Enemy/Shrek_the_Snek.png");
		enemy_health = 70;
		m_speed = 10;
		sprite->GetTransformComp().SetScaling(VectorF(1.5, 1.5));
		break;
	}

	sprite->GetTransformComp().SetOriginToCentreOfFrame();
	
	//sprite->SetAutoAnimate(20, true, "Right");
	m_Checkpoint = 0;
	m_Xp = xp;
	m_Position = { 650,-100 };
	m_Position.y += yPos;
	m_Alive = true;
	m_Died = false;

}

void EnemyAI::render(int &yOffset)
{
		sprite->GetTransformComp().SetPosition(VectorF(m_Position.x, m_Position.y - yOffset));
		sprite->Render(SCREEN_SURFACE);
}

void EnemyAI::move(const std::vector<HAPISPACE::VectorF> &path)
{
	if (m_Checkpoint < path.size())
	{
		if (m_Position.DistanceBetween(path[m_Checkpoint]) < 1)
		{
			if (m_Checkpoint + 1 < path.size())
				m_Checkpoint++;
			else
				m_Alive = false;
		}
		if (m_Position.x > path[m_Checkpoint].x)
		{
			m_Position.x -= 0.1 * m_speed;
		}
		else if (m_Position.x < path[m_Checkpoint].x)
		{
			m_Position.x += 0.1 * m_speed;
		}
		else if (m_Position.y > path[m_Checkpoint].y)
		{
			m_Position.y -= 0.1 * m_speed;
		}
		else if (m_Position.y < path[m_Checkpoint].y)
		{
			m_Position.y += 0.1 * m_speed;
		}
	}
	sprite->GetTransformComp().SetPosition(m_Position);
}

bool EnemyAI::isAlive()
{
	return m_Alive;
}

void EnemyAI::die()
{
	if (!m_Died)
	{
		if (enemy_health <= 0)
		{
			m_Xp->addXp(5);
			m_Xp->addCurrency(2);
		}
		else
		{
			m_Xp->addXp(2);
			m_Xp->addCurrency(1);
		}
		m_Alive = false;
		m_Died = true;
	}
	//include smoke puff animation
}

void EnemyAI::update(int &yOffset, const std::vector<HAPISPACE::VectorF> &path)
{
	if (isAlive())
	{
		move(path);
		render(yOffset);
	}
}