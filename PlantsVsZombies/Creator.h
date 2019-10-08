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

	/* 000 */ virtual ~Creator() {}; // Remember that inside the object there are virtual functions, which means that at address 0000, there is a table of virtual functions
	/* 004 */


	/* 0004 */ unsigned long __uUnkValue0004[0x15F6 - 1]; // We divide 0x57D8u by 4 since we use the long type, 
														  //and 0x57D8u is the size in bytes. -1 because the first 4 bytes is a pointer to a table of virtual functions
	/* 57D8 */ CreatorEx objCreatorEx; 
	/* 57E0 */
};

extern Creator* g_Creator;

CompileTimeSizeCheck(Creator, 0x57E0);

