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

	/* 000 */ virtual ~Creator() {}; // Помним что внутри объекта есть виртуальные функции, а значит по адресу 0000, лежит таблица виртуальных функций
	/* 004 */


	/* 0004 */ unsigned long __uUnkValue0004[0x15F6 - 1]; // 0x57D8u делим на 4 так как мы используем тип long, 
														  //а 0x57D8u размер в байтах. -1 потому что первые 4 байта это указатель на таблицу виртуальных функций
	/* 57D8 */ CreatorEx objCreatorEx; 
	/* 57E0 */
};

extern Creator* g_Creator;

CompileTimeSizeCheck(Creator, 0x57E0);

