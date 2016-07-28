#include "stdafx.h"
#include "FixGame.h"
#include <random>

HANDLE hThread = INVALID_HANDLE_VALUE;

DWORD WINAPI ThreadProc(LPVOID lpPtr)
{
	while (true)
	{
		if ((::GetAsyncKeyState(VK_F5) & 0xFF) != 0)
		{
			if (g_Creator)
			{
				::Sleep(50);

				g_Creator->objCreatorEx.PushSun();
			}
		}
	}

	return 0;
}

void FixGame::Initialize(void)
{
	BYTE bytes[] = { 0xB1, 0x01, 0x90 };
	WriteMemoryBYTES(0x005D14BD, bytes, 3); // patch pause

	Creator::Initialize();

	Item::Initialize();

	hThread = ::CreateThread(NULL, 0, ThreadProc, NULL, NULL, NULL);
}