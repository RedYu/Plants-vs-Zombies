#include "stdafx.h"

void DllInitializer(HMODULE hDllModule)
{
	// Check the memmory space of DLL
	if (((UINT64)hDllModule) < 0x7E000000 && ((UINT64)(&hGame)) < 0x7F000000)
	{
		// Check the game PlantsVsZombies                
		if (*((UINT64*)0x401000) == 0xAE76E8CE8B575553)
		{
			// Open the game process
			if ((hGame = OpenProcess(PROCESS_ALL_ACCESS | PROCESS_VM_READ | PROCESS_VM_WRITE, FALSE, GetCurrentProcessId())))
			{
				FixGame::Initialize();

				CloseHandle(hGame);
				hGame = NULL;
			}
			else
			{
				Msg(_T("Load error"), _T("[%s]\nAccess to the game was not granted"), __WFILE__);
				ExitProcess(1);
			}
		}
		else
		{
			Msg(_T("Load error"), _T("[%s]\nThis is not a PlantsVsZombies game \nOr DLL is not compatible with this version of the game"), __WFILE__);
			ExitProcess(1);
		}
	}
	else
	{
		Msg(_T("Load error"), _T("[%s]\nBad DLL location in the memory"), __WFILE__);
		ExitProcess(1);
	}
}

__declspec(dllexport) BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		DllInitializer(hModule);
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

