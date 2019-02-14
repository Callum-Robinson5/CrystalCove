#pragma once
class Worldspace
{
public:
	Worldspace();
	~Worldspace();

	int m_width{ 1280 };
	int m_height{ 800 };
	int m_difficulty{ 1 };

	void Game();
	void Initialise();
	void Createfile();
};

