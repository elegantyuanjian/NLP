#pragma once
#include "head.h"
class EvaluateSystem
{
public:
	EvaluateSystem(void);
	~EvaluateSystem(void);

	float getPrecision();
	float getRecall();
	float getFMeasure();

    void setSystem_Result(string result);
	void setSystem_Standard(string standard);
	void setParam();
private:

	//void setParam();

	void splistSegment(map<int,string> *,string splitstring);

	string result;
	string stadard;

	int systemandstandard;
    int system_out;
	int standard_out;

	float precision;
	float recalll;
};

