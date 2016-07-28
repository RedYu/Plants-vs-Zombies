#include "stdafx.h"
#include "Creator.h"

Creator* g_Creator = NULL;

void Creator::CreateItem(int posX, int posY, ItemType item, ItemSpeed speed)
{
	typedef void(__thiscall *t)(Creator*, int, int, ItemType, ItemSpeed);
	t f = (t)0x0040F400;
	f(this, posX, posY, item, speed);
}

int __cdecl Creator::GameRandom(int nRange)
{
	typedef unsigned int(__cdecl *t)(int);
	t f = (t)0x005FF2A0;
	return f(nRange);
}

LPVOID __fastcall Creator::Constructor(LPVOID lpPtr, LPVOID /* edx */, Creator* pCreator)
{
	typedef Creator*(__thiscall *t)(LPVOID, Creator*);
	t f = (t)0x0040A3C0;

	g_Creator = pCreator;

	Creator* pReturn = f(lpPtr, pCreator);
	new (&pCreator->objCreatorEx) CreatorEx;

	return pReturn;
}

Creator* __fastcall Creator::Destructor(Creator* pCreator, LPVOID /* edx */, bool bIsMemoryFreeUsed)
{
	if (g_Creator == pCreator)
		g_Creator = NULL;

	pCreator->objCreatorEx.~CreatorEx();
	
	typedef Creator*(__thiscall *t)(Creator*, bool);
	t f = (t)0x0040AF10;
	return f(pCreator, bIsMemoryFreeUsed);
}

void Creator::Initialize(void)
{
	WriteMemoryDWORD(0x004528CF, sizeof(Creator)); // patch new size
	WriteInstructionCall(0x004528EE, (UINT)Creator::Constructor);
	WriteMemoryDWORD(0x006E4D38, (UINT)Creator::Destructor);
}