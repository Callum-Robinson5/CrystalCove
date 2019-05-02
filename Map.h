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

	int backgroundType{ 0 };

	std::vector<HAPISPACE::VectorF> m_Path;
	std::shared_ptr<HAPISPACE::Sprite> grass = HAPI_Sprites.MakeSprite("Data\\Tilemaps\\Grass1.png");
	std::shared_ptr<HAPISPACE::Sprite> dirt = HAPI_Sprites.MakeSprite("Data\\Tilemaps\\Dirt1.png");
	std::shared_ptr<HAPISPACE::Sprite> magma = HAPI_Sprites.MakeSprite("Data\\Tilemaps\\Molten_Magma1.png");
	std::shared_ptr<HAPISPACE::Sprite> mud = HAPI_Sprites.MakeSprite("Data\\Tilemaps\\Mud1.png");
	std::shared_ptr<HAPISPACE::Sprite> sand = HAPI_Sprites.MakeSprite("Data\\Tilemaps\\Sand1.png");
	std::shared_ptr<HAPISPACE::Sprite> water = HAPI_Sprites.MakeSprite("Data\\Tilemaps\\Water1.png");
	std::shared_ptr<HAPISPACE::Sprite> obsidian = HAPI_Sprites.MakeSprite("Data\\Tilemaps\\Solid_Magma1.png");
	std::shared_ptr<HAPISPACE::Sprite> scales = HAPI_Sprites.MakeSprite("Data\\Tilemaps\\Scales_NEW.png");
	std::shared_ptr<HAPISPACE::Sprite> scalesCorner = HAPI_Sprites.MakeSprite("Data\\Tilemaps\\ScalesCorner_NEW_NEW_NEW.png");
};

