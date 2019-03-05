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

	sprite->GetTransformComp().SetPosition(m_Position);
	sprite->GetTransformComp().SetScaling({ 0.3f, 0.3f });
	sprite->GetTransformComp().SetRotation(0.1f);

}

void EnemyAI::render(int &yOffset)
{
	sprite->GetTransformComp().SetPosition(VectorF(m_Position.x, m_Position.y - yOffset));
	sprite->Render(SCREEN_SURFACE);
}

void EnemyAI::move(const std::vector<HAPISPACE::VectorF> &path)
{
	if (m_Checkpoint + 1 < path.size())
	{
		if (m_Position.x < path[m_Checkpoint + 1].x && m_Position.y < path[m_Checkpoint + 1].y)
		{
			m_Position = m_Position + VectorF(10, 10).Normalized();
		}
		else if (m_Position.x < path[m_Checkpoint + 1].x && m_Position.y > path[m_Checkpoint + 1].y)
		{
			m_Position = m_Position + VectorF(10, -10).Normalized();
		}
		else if (m_Position.x > path[m_Checkpoint + 1].x && m_Position.y < path[m_Checkpoint + 1].y)
		{
			m_Position = m_Position + VectorF(-10, 10).Normalized();
		}
		else if (m_Position.x > path[m_Checkpoint + 1].x && m_Position.y > path[m_Checkpoint + 1].y)
		{
			m_Position = m_Position + VectorF(-10, -10).Normalized();
		}
		else if (m_Position.x > path[m_Checkpoint + 1].x)
		{
			m_Position.x -= m_speed;
		}
		else if (m_Position.x < path[m_Checkpoint + 1].x)
		{
			m_Position.x += m_speed;
		}
		else if (m_Position.y > path[m_Checkpoint + 1].y)
		{
			m_Position.y -= m_speed;
		}
		else if (m_Position.y < path[m_Checkpoint + 1].y)
		{
			m_Position.y += m_speed;
		}
		if (m_Position.DistanceBetween(path[m_Checkpoint + 1]) < 2)
		{
			m_Checkpoint++;
		}
	}
	else
	{
		m_Checkpoint = 0;
	}
	sprite->GetTransformComp().SetPosition(m_Position);
}

void EnemyAI::health()
{
	enemy_health = 10;
	if (enemy_health <= 0)
	{
		//kill sprite
	}

	while (enemy_health > 0)
	{
		//continue moving
	}
}

void EnemyAI::update()
{
	while (HAPI_Sprites.Update())
	{
		spawn();
	}
}