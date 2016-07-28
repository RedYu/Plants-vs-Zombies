#pragma once

struct UnkStructItem
{
	/* 0000 */ unsigned long __uUnkValue0000[4];
	/* 0010 */ unsigned long dwRandValue1; // range(0 - 2)
	/* 0014 */ unsigned long __uUnkValue0014[6];
	/* 002C */ unsigned long dwRandValue2; // range(0 - 3) + 3
	/* 0030 */ unsigned long __uUnkValue0030[10];
	/* 0058 */
};

CompileTimeSizeCheck(UnkStructItem, 0x58);

class Item
{
public:
	static void Initialize(void);
	static int __fastcall Constructor(Item* pItem, int nResult);

	unsigned int GetMaxWaitTime(void);

	/* 0000 */ void* __uPtrAppBase;
	/* 0004 */ Creator* pCreator;
	/* 0008 */ unsigned long __uUnkValue0008[4];
	/* 0018 */ BOOL nIsVisible; // ���� ��������� ����� 0, ������ ����� �� �� �������� �� ������
	/* 001C */ unsigned long __uUnkValue001C[2];
	/* 0024 */ POINTFLOAT pCurrentPosition; // ������� ���������� �� ������
	/* 002C */ POINTFLOAT pStepPosition; // ��� �������� �� ��� X / Y
	/* 0034 */ float fScale; // ������
	/* 0038 */ BOOL nIsDie; // ���� ����� ��������� 1, ������ ��� �� ��������
	/* 003C */ DWORD dwTimeToDie; // ��� ����� ������� � ���, ����� ������� ����� ������, ��� ��������� �� ������ ����� 0, ����� ������ ��������� � ����� �������� ����� ����� 750, ����� �������� 15
	/* 0040 */ unsigned long __uUnkValue0040[2];
	/* 0048 */ float fPositionWait; // ��� ���������� �� ��� Y, ������� ������� ��������� ����� ��������� ������
	/* 004C */ DWORD dwTimeLife; // ��� ����� ���� �����, �� ��������� �� ������
	/* 0050 */ BOOL nIsPickUp; // ���� ����� ��������� 1 ������ ��� �� ����������
	/* 0054 */ DWORD dwTimeWait; // ����� ��������, ����� ������ ��������� �� �����, ���� ���������� ����� ��������
	/* 0058 */ ItemType eType; // ��� �� ������� ������, �� ���� �����
	/* 005C */ unsigned long __uUnkValue005C[5];
	/* 0070 */ UnkStructItem __uUnkStruct;
	/* 00C8 */ bool bIsShowsArrow; // ����� �� ���������� ������� ��� �������, ������������ �� ��� ������ ����� ���������
	/* 00C9 */ bool __uUnkValueC9;
	/* 00CA */ bool bIsDown; // ������� ��������� �� ������ �� �����
	/* 00CB */ bool __uUnkValueCB;
	/* 00CC */ unsigned long __uUnkValue00CC;
	/* 00D0 */ unsigned long dwID;
	/* 00D4 */ unsigned long __uUnkValue00D4;
	/* 00D8 */
};

CompileTimeSizeCheck(Item, 0xD8);
