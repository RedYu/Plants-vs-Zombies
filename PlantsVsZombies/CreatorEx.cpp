#include "stdafx.h"
#include "CreatorEx.h"


CreatorEx::CreatorEx()
	: bInit(false)
{
	this->dwMyCountSuns = 0;
	this->bInit = true;
}


CreatorEx::~CreatorEx()
{
}


void CreatorEx::PushSun(void)
{
	if (this->bInit && g_Creator)
	{
		this->dwMyCountSuns++;

		POINT pos;

		pos.x = Creator::GameRandom(550) + 100;
		pos.y = 60;

		g_Creator->CreateItem(pos.x, pos.y, Sun25, NORMAL);
	}
}

unsigned long CreatorEx::GetCountSuns(void) const
{
	return this->dwMyCountSuns;
}
