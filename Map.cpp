#include "Map.h"



Map::Map()
{
	memset(m_MapData, 0, m_Width * m_Height);
}


Map::~Map()
{
}

bool Map::GeneratePath(int Difficulty)
{
	bool* pointer = m_MapData;

	//Initiating the Map by setting all values to 0
	memset(m_MapData, 0, m_Width * m_Height);

	//Values for traversing the Map array
	int Left = -1;
	int Right = 1;
	int Down = m_Width;


	char lastDirection;

	//Value to define which member of the Map array is "selected"
	int position = m_Width / 2;

	//(Re)Setting all the values in the Map to 0
	memset(m_MapData, 0, m_Height * m_Width);
	position = m_Width / 2;

	pointer = m_MapData;
	pointer += position;
	*pointer = 1;


	m_Path.clear();


	//Continues randomly generating path until it has reached the bottom of the screen
	while (position < m_Width * m_Height - m_Width)
	{
		//Creating a value to be changed once a valid direction for the path to move has been selected
		bool Continue{ false };
		while (!Continue)
		{
			//Switch case to randomly select the direction for the path to go
			switch (rand() % 7)
			{
				//cases 0-2 make the path to go right
			case 0:

			case 1:

			case 2:
				if (lastDirection != 'r' && (position % m_Width) != 0) {
					pointer += Left;
					position += Left;
					lastDirection = 'l';
					*pointer = 1;
					Continue = true;
				}
				break;
				//cases 3-5 make the path go left
			case 3:

			case 4:

			case 5:
				if (lastDirection != 'l' && (position % m_Width) != m_Width - 1) {
					pointer += Right;
					position += Right;
					lastDirection = 'r';
					*pointer = 1;
					Continue = true;
				}
				break;
				//case 6 makes the path go down
			case 6:
				pointer += Down;
				position += Down;
				lastDirection = 'd';
				*pointer = 1;
				if (position < m_Width* m_Height - m_Width)
				{
					m_Path.push_back(HAPISPACE::VectorI(position % m_Width, (position - (position % m_Width)) / m_Width));
					pointer += Down;
					position += Down;
					*pointer = 1;
				}
				Continue = true;
				break;
			default:
				return false;
				break;
			}
		}
		m_Path.push_back(HAPISPACE::VectorI(position % m_Width, (position - (position % m_Width)) / m_Width));
	}

	return true;
}

void Map::RenderMap(int yOffset)
{
	std::shared_ptr<HAPISPACE::Sprite> green = HAPI_Sprites.MakeSprite("Data\\Green.jpg");
	std::shared_ptr<HAPISPACE::Sprite> pink = HAPI_Sprites.MakeSprite("Data\\Pink.jpg");
	bool* pointer = m_MapData;
	for (int i{ 0 }; i < m_Height; i++)
	{
		for (int j{ 0 }; j < m_Width; j++)
		{
			if (*pointer == 0)
			{
				green->GetTransformComp().SetPosition({ (float)(j * 40), (float)(i * 40) });
				green->Render(SCREEN_SURFACE);
				//HAPI_Sprites.RenderText(VectorI(j * 32, i * 40), Colour255::GREEN, std::to_string(*pointer), 20);
				pointer++;
			}
			else
			{
				pink->GetTransformComp().SetPosition({ (float)(j * 40), (float)(i * 40) });
				pink->Render(SCREEN_SURFACE);
				//HAPI_Sprites.RenderText(VectorI(j * 32, i * 40), Colour255::MAGENTA, std::to_string(*pointer), 20);
				pointer++;
			}
		}
	}
}
