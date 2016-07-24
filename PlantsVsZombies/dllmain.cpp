#include "stdafx.h"

void DllInitializer(HMODULE hDllModule)
{
	// �������� ������������ ����� ���������� 
	if (((UINT64)hDllModule) < 0x7E000000 && ((UINT64)(&hGame)) < 0x7F000000)
	{
		// ������� ���� PlantsVsZombies                
		if (*((UINT64*)0x401000) == 0xAE76E8CE8B575553)
		{
			// ��������� ������� ����
			if ((hGame = OpenProcess(PROCESS_ALL_ACCESS | PROCESS_VM_READ | PROCESS_VM_WRITE, FALSE, GetCurrentProcessId())))
			{
				FixGame::Initialize();

				CloseHandle(hGame);
				hGame = NULL;
			}
			else
			{
				Msg(_T("������ ��� ��������"), _T("[%s]\n�� ��� ����� ������ � ����"), __WFILE__);
				ExitProcess(1);
			}
		}
		else
		{
			Msg(_T("������ ��� ��������"), _T("[%s]\n��� �� ���� PlantsVsZombies\n��� DLL �� ���������� � ���� ������� ����"), __WFILE__);
			ExitProcess(1);
		}
	}
	else
	{
		Msg(_T("������ ��� ��������"), _T("[%s]\n������ ���������� DLL � ������"), __WFILE__);
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

