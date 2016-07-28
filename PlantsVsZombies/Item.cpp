#include "stdafx.h"
#include "Item.h"


__declspec(naked) void ItemNakedConstructor(void)
{
	// Так как edx свободный будем с ним и работать, и он же подойдет к __fastcall
	__asm
	{
		mov edx, 00432C60h			// это указатель на оригинальную функцию 
		call edx					// вызываем сперва настоящий конструктор

									// в ecx находится указатель на предмет
									// точно нужно для __fastcall

		mov edx, eax				// передаем результат оригинальной функции
		call Item::Constructor		// вызываем наш конструктор, 
									// так как настоящий конструктор пропатчен, 
									// данные в стеке сохранятся и попадук к нам

		mov edx, 0040F448h			// адрес возврата
		jmp edx						// идем домой
	}
}


int __fastcall Item::Constructor(Item* pItem /* ecx */, int nResult /* edx */)
{
	/* 
		Теперь мы можем делать с pItem что угодно:)
	*/

	pItem->nIsPickUp = TRUE; // Сделаем чтобы предмет автоматически подбирался, но это мне повезло с тем что есть такой параметр
							 // Но попробуем позже перехватит функцию подбора, и заставить её работать на нас

	return nResult; // Вернем на всякий случай результат оригинального конструктора
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