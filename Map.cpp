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

	m_Path.push_back(HAPISPACE::VectorF((position % m_Width) * 100, ((position - (position % m_Width)) / m_Width) * 100));
	if (Difficulty == 0)
	{
		while (position < m_Width * m_Height - m_Width)
		{
			//Creating a value to be changed once a valid direction for the path to move has been selected
			bool Continue{ false };
			while (!Continue)
			{
				//Switch case to randomly select the direction for the path to go
				switch (rand() % 4)
				{
				//cases 0-2 make the path to go right
				case 0:

					if (lastDirection != 'r') 
					{
						while ((position % m_Width) > 1)
						{
							pointer += Left;
							position += Left;
							lastDirection = 'l';
							*pointer = 1;
							m_Path.push_back(HAPISPACE::VectorF((position % m_Width)*100, ((position - (position % m_Width)) / m_Width)*100));
							Continue = true;
						}
					}
					break;
					//cases 3-5 make the path go left

				case 1:
					if (lastDirection != 'l')
					{
						while ((position % m_Width) < m_Width - 2)
						{
							pointer += Right;
							position += Right;
							lastDirection = 'r';
							*pointer = 1;
							m_Path.push_back(HAPISPACE::VectorF((position % m_Width) * 100, ((position - (position % m_Width)) / m_Width) * 100));
							Continue = true;
						}
					}
					break;
					//case 6 makes the path go down
				case 2:

				case 3:
					pointer += Down;
					position += Down;
					lastDirection = 'd';
					*pointer = 1;
					if (position < m_Width* m_Height - m_Width)
					{
						m_Path.push_back(HAPISPACE::VectorF((position % m_Width) * 100, ((position - (position % m_Width)) / m_Width) * 100));
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
		}
	}
	else if(Difficulty == 1)
	{
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
					if (lastDirection != 'r' && (position % m_Width) > 1) {
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
					if (lastDirection != 'l' && (position % m_Width) < m_Width - 2) {
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
						m_Path.push_back(HAPISPACE::VectorF((position % m_Width) * 100, ((position - (position % m_Width)) / m_Width) * 100));
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
			m_Path.push_back(HAPISPACE::VectorF((position % m_Width) * 100, ((position - (position % m_Width)) / m_Width) * 100));
		}
	}
	else
	{
		while (position < m_Width * m_Height - m_Width)
		{
		//Creating a value to be changed once a valid direction for the path to move has been selected
		
			bool Continue{ false };
			while (!Continue)
			{
				//Switch case to randomly select the direction for the path to go
				switch (rand() % 7)
				{
				case 0:
					//case 0 makes the path to go right
					if (lastDirection != 'r' && (position % m_Width) > 1) {
						pointer += Left;
						position += Left;
						lastDirection = 'l';
						*pointer = 1;
						Continue = true;
					}
					break;
				case 1:
					//case 1 makes the path to go right
					if (lastDirection != 'l' && (position % m_Width) < m_Width - 2) {
						pointer += Right;
						position += Right;
						lastDirection = 'r';
						*pointer = 1;
						Continue = true;
					}
					break;
				case 2:
					//cases 2-6 makes the path to go down
				case 3:

				case 4:

				case 5:
					
				case 6:
					pointer += Down;
					position += Down;
					lastDirection = 'd';
					*pointer = 1;
					if (position < m_Width* m_Height - m_Width)
					{
						m_Path.push_back(HAPISPACE::VectorF(position % m_Width, (position - (position % m_Width)) / m_Width));
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

	}

	return true;
}

void Map::RenderMap(int &yOffset)
{
	if (yOffset < 0)
		yOffset = 0;
	else if (yOffset > 100 * (m_Height - 8))
		yOffset = 100 * (m_Height - 8);
	std::shared_ptr<HAPISPACE::Sprite> green = HAPI_Sprites.MakeSprite("Data\\Grass.png");
	green->GetTransformComp().SetScaling({ 2.5,2.5 });
	std::shared_ptr<HAPISPACE::Sprite> pink = HAPI_Sprites.MakeSprite("Data\\Sand.png");
	pink->GetTransformComp().SetScaling({ 2.5,2.5 });
	bool* pointer = m_MapData;
	for (int i{ 0 }; i < m_Height; i++)
	{
		for (int j{ 0 }; j < m_Width; j++)
		{
			if (*pointer == 0)
			{
				green->GetTransformComp().SetPosition({ (float)(j * 100), (float)((i * 100) - yOffset) });
				green->Render(SCREEN_SURFACE);
				//HAPI_Sprites.RenderText(VectorI(j * 32, i * 40), Colour255::GREEN, std::to_string(*pointer), 20);
				pointer++;
			}
			else if(*pointer == 1)
			{
				pink->GetTransformComp().SetPosition({ (float)(j * 100), (float)((i * 100) - yOffset) });
				pink->Render(SCREEN_SURFACE);
				//HAPI_Sprites.RenderText(VectorI(j * 32, i * 40), Colour255::MAGENTA, std::to_string(*pointer), 20);
				pointer++;
			}
		}
	}
}

void Map::SelectTile(const int & mouseX, const int & mouseY, const int & yOffset)
{
}
