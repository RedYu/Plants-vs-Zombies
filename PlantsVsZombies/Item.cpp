#include "stdafx.h"
#include "Item.h"


__declspec(naked) void ItemNakedConstructor(void)
{
	// ��� ��� edx ��������� ����� � ��� � ��������, � �� �� �������� � __fastcall
	__asm
	{
		mov edx, 00432C60h			// ��� ��������� �� ������������ ������� 
		call edx					// �������� ������ ��������� �����������

									// � ecx ��������� ��������� �� �������
									// ����� ����� ��� __fastcall

		mov edx, eax				// �������� ��������� ������������ �������
		call Item::Constructor		// �������� ��� �����������, 
									// ��� ��� ��������� ����������� ���������, 
									// ������ � ����� ���������� � ������� � ���

		mov edx, 0040F448h			// ����� ��������
		jmp edx						// ���� �����
	}
}


int __fastcall Item::Constructor(Item* pItem /* ecx */, int nResult /* edx */)
{
	/* 
		������ �� ����� ������ � pItem ��� ������:)
	*/

	pItem->nIsPickUp = TRUE; // ������� ����� ������� ������������� ����������, �� ��� ��� ������� � ��� ��� ���� ����� ��������
							 // �� ��������� ����� ���������� ������� �������, � ��������� � �������� �� ���

	return nResult; // ������ �� ������ ������ ��������� ������������� ������������
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