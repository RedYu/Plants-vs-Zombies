#pragma once
#include "CreatorEx.h"

class Creator
{
	Creator() {};
public:
	static int __stdcall sub_40D840(Creator* pCreator);

	void CreateSun(int a2, int a3, int a4, int a5);

	/* 000 */ virtual ~Creator() {}; // Помним что внутри объекта есть виртуальные функции, а значит по адресу 0000, лежит таблица виртуальных функций
	/* 004 */


	/* 0004 */ unsigned long __uUnkValue0004[0x15F6 - 1]; // 0x57D8u делим на 4 так как мы используем тип long, 
														  //а 0x57D8u размер в байтах. -1 потому что первые 4 байта это указатель на таблицу виртуальных функций
	/* 57D8 */ CreatorEx objCreatorEx; 
	/* 57E0 */
};

extern Creator* g_Creator;

CompileTimeSizeCheck(Creator, 0x57E0);