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
	/* 0018 */ BOOL nIsVisible; // Если поставить здесь 0, солнце живет но не рисуется на экране
	/* 001C */ unsigned long __uUnkValue001C[2];
	/* 0024 */ POINTFLOAT pCurrentPosition; // Текущие координаты на экране
	/* 002C */ POINTFLOAT pStepPosition; // Шаг движения по оси X / Y
	/* 0034 */ float fScale; // Маштаб
	/* 0038 */ BOOL nIsDie; // Если здесь поставить 1, солнце тут же пропадет
	/* 003C */ DWORD dwTimeToDie; // Это время говорит о том, через сколько умрет солнце, при появлении на экране равно 0, когда солнце опустится и время ожидания будет равно 750, здесь появится 15
	/* 0040 */ unsigned long __uUnkValue0040[2];
	/* 0048 */ float fPositionWait; // Это координата по оси Y, которая говорит насколько низко опустится солнцу
	/* 004C */ DWORD dwTimeLife; // Это время всей жизни, от появления на экране
	/* 0050 */ BOOL nIsPickUp; // Если здесь поставить 1 солнце тут же подберется
	/* 0054 */ DWORD dwTimeWait; // Время ожидания, когда солнце находится на земле, идет увеличение этого значения
	/* 0058 */ ItemType eType; // Что за предмет создан, об этом позже
	/* 005C */ unsigned long __uUnkValue005C[5];
	/* 0070 */ UnkStructItem __uUnkStruct;
	/* 00C8 */ bool bIsShowsArrow; // Будет ли отображтся стрелка над солнцем, обозначающая то что солнце нужно подобрать
	/* 00C9 */ bool __uUnkValueC9;
	/* 00CA */ bool bIsDown; // Говорит находится ли солнце на земле
	/* 00CB */ bool __uUnkValueCB;
	/* 00CC */ unsigned long __uUnkValue00CC;
	/* 00D0 */ unsigned long dwID;
	/* 00D4 */ unsigned long __uUnkValue00D4;
	/* 00D8 */
};

CompileTimeSizeCheck(Item, 0xD8);
