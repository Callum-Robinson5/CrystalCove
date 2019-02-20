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
	void setXp(int i);
	void setLevel(int j);
	int getCurrency();
	void setCurrency(int k);
	void addCurrency(int l);


private:

	int m_xpToAdd;
	int m_totalXp{ 0 };
	int m_level{ 1 };
	int m_difficultyMod;
	int m_test;
	int m_currency{ 0 };

};

