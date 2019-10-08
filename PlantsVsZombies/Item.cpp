#include "stdafx.h"
#include "Item.h"


__declspec(naked) void ItemNakedConstructor(void)
{
	// Since edx is free we will work with it, and it will also suit __fastcall
	__asm
	{
		mov edx, 00432C60h			// this is a pointer to the original function
		call edx					// first we call the real constructor

									// in ecx is a pointer to an item
									// definitely needed for __fastcall

		mov edx, eax				// pass the result of the original function
		call Item::Constructor		// we call our constructor,
									// since the real constructor is patched,
									// data on the stack will be saved and get to us

		mov edx, 0040F448h			// return address
		jmp edx						// let's go home
	}
}


int __fastcall Item::Constructor(Item* pItem /* ecx */, int nResult /* edx */)
{
	/* 
		Now we can do anything with pItem :)
	*/

	pItem->nIsPickUp = TRUE; // Let's make the item automatically selected, but I was lucky with the fact that there is such a parameter
							 // But we will try later to intercept the selection function, and make it work for us

	return nResult; // We will return just in case the result of the original constructor
}


void Item::Initialize(void)
{
	WriteInstructionJmp(0x0040F443, (UINT)ItemNakedConstructor);
}


unsigned int Item::GetMaxWaitTime(void)
{
	typedef unsigned int(__thiscall *t)(Item*);
	t f = (t)0x00435DA0;
	return f(this);
}