#include "EnemyAI.h"
#include <HAPISprites_Lib.h>
using namespace HAPISPACE;

EnemyAI::EnemyAI()
{
}

EnemyAI::~EnemyAI()
{
}

void EnemyAI::spawn()
{
	if (!sprite)
	{
		HAPI_Sprites.UserMessage("Could not load spritesheet", "Error");
		return;
	}

	//sprite->SetAutoAnimate(20, true, "Right");

	m_Position = { 16 * 40,-100 };
	sprite->GetTransformComp().SetScaling({ 0.3f, 0.3f });
	sprite->GetTransformComp().SetRotation(0.1f);
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
	if (enemy_health <= 0 || !m_Alive)
	{
		if (!m_Died)
			die();
		return false;
	}
	return true;
}

void EnemyAI::die()
{
	m_Alive = false;
	m_Died = true;
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