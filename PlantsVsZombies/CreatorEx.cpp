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


void CreatorEx::Increment(void)
{
	if (this->bInit)
		this->dwMyCountSuns++;
}

unsigned long CreatorEx::GetCountSuns(void) const
{
	return this->dwMyCountSuns;
}