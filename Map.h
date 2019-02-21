#pragma once
#include <vector>
#include <HAPISprites_Lib.h>
class Map
{
public:
	Map();
	~Map();

	bool GeneratePath(int Difficulty = 70);
	void RenderMap(int yOffset);

private:
	const int m_Width{ 32 };
	const int m_Height{ 40 };
	bool m_MapData[2000];
	std::vector<HAPISPACE::VectorI> m_Path;
};

