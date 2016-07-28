#pragma once
#include "Creator.h"

class CreatorEx
{
public:
	CreatorEx();
	~CreatorEx();

	void PushSun(void);
	unsigned long GetCountSuns(void) const;
private:
	unsigned long dwMyCountSuns;
	bool bInit;
};

CompileTimeSizeCheck(CreatorEx, 0x0008);