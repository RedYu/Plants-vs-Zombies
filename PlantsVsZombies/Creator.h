#pragma once
#include "CreatorEx.h"

class Creator
{
	Creator() 
	{};
public:
	static void Initialize(void);

	static LPVOID __fastcall Constructor(LPVOID lpPtr, LPVOID, Creator* pCreator);
	static Creator* __fastcall Destructor(Creator* pCreator, LPVOID, bool bIsMemoryFreeUsed);
	static int __cdecl GameRandom(int nRange);

	void CreateItem(int posX, int posY, ItemType item, ItemSpeed speed);

	/* 000 */ virtual ~Creator() {}; // ������ ��� ������ ������� ���� ����������� �������, � ������ �� ������ 0000, ����� ������� ����������� �������
	/* 004 */


	/* 0004 */ unsigned long __uUnkValue0004[0x15F6 - 1]; // 0x57D8u ����� �� 4 ��� ��� �� ���������� ��� long, 
														  //� 0x57D8u ������ � ������. -1 ������ ��� ������ 4 ����� ��� ��������� �� ������� ����������� �������
	/* 57D8 */ CreatorEx objCreatorEx; 
	/* 57E0 */
};

extern Creator* g_Creator;

CompileTimeSizeCheck(Creator, 0x57E0);

