#include "stdafx.h"
#include "Creator.h"

Creator* g_Creator = NULL;

void Creator::CreateSun(int a2, int a3, int a4, int a5)
{
	typedef void(__thiscall *t)(Creator*, int, int, int, int);
	t f = (t)0x0040F400;
	f(this, a2, a3, a4, a5);
}


int __stdcall Creator::sub_40D840(Creator* pCreator)
{
	typedef int(__stdcall *t)(Creator*);
	t f = (t)0x0040D840;

	new (&pCreator->objCreatorEx) CreatorEx();

	g_Creator = pCreator;

	return f(pCreator);
}


