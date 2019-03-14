#include "TowerAI.h"
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
	m_Position = { (float)mouseData.x, (float)mouseData.y + yOffset};
	sprite->GetTransformComp().SetScaling({ 0.3f, 0.3f });
	sprite->GetTransformComp().SetRotation(0.0f);
	m_Spawned = true;

}

void TowerAI::render(int &yOffset)
{
	if (m_Spawned)
	{
		sprite->GetTransformComp().SetPosition(VectorF(m_Position.x, m_Position.y - yOffset));
		sprite->Render(SCREEN_SURFACE);
	}
}