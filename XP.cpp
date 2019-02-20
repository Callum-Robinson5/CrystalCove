#include "XP.h"
#include <iostream>



XP::XP()
{
}


XP::~XP()
{
}

void XP::updateXp()
{
	int xpToLevel = m_level * 135;
	if (m_totalXp >= xpToLevel)
	{
		m_level += 1;
		m_totalXp = 0;
	}
}

void XP::addXp(int xP)
{
	m_totalXp += xP * m_difficultyMod;
}

void XP::difficulty(int dif)
{
	if (dif == 1)
	{
		m_difficultyMod = 1;
	}
	if (dif == 2)
	{
		m_difficultyMod = 2;
	}
	if (dif == 3)
	{
		m_difficultyMod = 3;
	}
}

int XP::getXp()
{
	return m_totalXp;
}

int XP::getLevel()
{
	return m_level;
}

void XP::setXp(int i)
{
	m_totalXp = i;
}

void XP::setLevel(int j)
{
	m_level = j;
}

int XP::getCurrency()
{
	return m_currency;
}

void XP::setCurrency(int k)
{
	m_currency = k;
}

void XP::addCurrency(int l)
{
	m_currency += l;
}

