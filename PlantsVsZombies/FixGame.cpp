#include "stdafx.h"
#include "FixGame.h"


void FixGame::Initialize(void)
{
	BYTE bytes[] = { 0xB1, 0x01, 0x90 };
	WriteMemoryBYTES(0x005D14BD, bytes, 3);
}