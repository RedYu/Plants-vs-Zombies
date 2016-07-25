#include "stdafx.h"
#include "FixGame.h"


void FixGame::Initialize(void)
{
	BYTE bytes[] = { 0xB1, 0x01, 0x90 };
	WriteMemoryBYTES(0x005D14BD, bytes, 3);

	WriteMemoryDWORD(0x004528CF, sizeof(Creator)); // patch new size
	WriteInstructionCall(0x00452B48, (UINT)Creator::sub_40D840);
}