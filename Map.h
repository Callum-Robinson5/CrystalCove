#pragma once
#include <vector>
#include <HAPISprites_Lib.h>
class Map
{
public:
	Map();
	~Map();

	bool GeneratePath(int Difficulty = 70);
	void RenderMap(int &yOffset);
	const std::vector<HAPISPACE::VectorF>& GetPath() { return m_Path; };
	void SelectTile(const int & mouseX, const int & mouseY, const int &yOffset);

private:
	const int m_Width{ 10 };
	const int m_Height{ 30 };
	bool m_MapData[3200];
	std::vector<HAPISPACE::VectorF> m_Path;
	std::shared_ptr<HAPISPACE::Sprite> grass = HAPI_Sprites.MakeSprite("Data\\Tilemaps\\Grass1.png");
	std::shared_ptr<HAPISPACE::Sprite> path = HAPI_Sprites.MakeSprite("Data\\Tilemaps\\Sand1.png");
};

