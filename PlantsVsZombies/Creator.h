#pragma once
#include "CreatorEx.h"

class Creator
{
	Creator() {};
public:
	static int __stdcall sub_40D840(Creator* pCreator);

	void CreateSun(int a2, int a3, int a4, int a5);

	/* 000 */ virtual ~Creator() {}; // ������ ��� ������ ������� ���� ����������� �������, � ������ �� ������ 0000, ����� ������� ����������� �������
	/* 004 */


	/* 0004 */ unsigned long __uUnkValue0004[0x15F6 - 1]; // 0x57D8u ����� �� 4 ��� ��� �� ���������� ��� long, 
														  //� 0x57D8u ������ � ������. -1 ������ ��� ������ 4 ����� ��� ��������� �� ������� ����������� �������
	/* 57D8 */ CreatorEx objCreatorEx; 
	/* 57E0 */
};

extern Creator* g_Creator;

CompileTimeSizeCheck(Creator, 0x57E0);