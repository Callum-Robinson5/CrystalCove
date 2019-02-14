#pragma once

#include <HAPISprites_Lib.h>

using namespace HAPISPACE;
class XP
{
public:


	XP();
	~XP();
	void updateXp();
	void addXp(int xP);
	void difficulty(int dif);
	int getXp();
	int getLevel();

private:

	int m_xpToAdd;
	int m_totalXp{0};
	int m_level{1};
	int m_difficultyMod;
	int m_test;

};

