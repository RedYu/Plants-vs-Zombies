#pragma once
class CreatorEx
{
public:
	CreatorEx();
	~CreatorEx();

	void Increment(void);

	unsigned long GetCountSuns(void) const;

private:
	unsigned long dwMyCountSuns;
	bool bInit;
};

CompileTimeSizeCheck(CreatorEx, 0x0008);