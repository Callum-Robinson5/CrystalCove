#pragma once
#include "XP.h"
#include "Map.h"
#include "EnemyAI.h"
#include "TowerAI.h"
#include "Projectiles.h"
class Worldspace //: IHapiSpritesInputListener


{ 
public:
	Worldspace();
	~Worldspace();
	void Initialise();
	const VectorI GetScreenSize() { return m_ScreenSize; };

	std::vector<EnemyAI> GetEnemies() { return Enemies; };


	void ResetFile();
	

	

private:
	int m_width{ 1280 };
	int m_height{ 800 };
	VectorI m_ScreenSize{ 1280,800 };
	int m_difficulty{ 1 };
	int scrollValue{ 0 };

	int maxEnemies{ 50 };
	int maxTowers{ 50 };
	int maxProjectiles{ 100 };

	std::vector<EnemyAI> Enemies;
	std::vector<TowerAI> m_Towers;
	std::vector<Projectiles> m_Projectiles;
	
	class XP xp;
	void Game();
	void SpawnWave(int numEnemies, int distanceBetweenEnemies);
	void PlaceTower(VectorF position, Map & map, std::vector<TowerAI> & towers);
	void ConfigLoad();
	void SaveFile();
	void LoadFile();

/*
	// Called when HAPI Sprites detects a key event (repeatadly for key down, once for key up)
	void OnKeyEvent(EKeyEvent keyEvent, BYTE keyCode) override {}

	// Called when HAPI detects a mouse event other than mouse move
	void OnMouseEvent(EMouseEvent mouseEvent, const MouseData& mouseData) override {}

	// Non virtual as may not want to implement - gets a lot of calls 
	void OnMouseMove(const MouseData& mouseData) override {};

	// Called when HAPI Sprites detects a controller event - optional
	void OnControllerEvent(unsigned int controllerId, EControllerEvent controllerEvent, unsigned int buttonIndex,
		const ControllerData& controllerData) override {}

	// Called with interpreted key presses into character entry
	void OnTextEntered(char enteredText) override {}
*/
};

