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

    void setSystemResult(string result);
	void setSystemStandard(string standard);
	void setParam();
private:

	//void setParam();

	void splistSegment(map<int,string> *,string split_string);

	string result;
	string stadard;

	int system_and_standard;
    int system_out;
	int standard_out;

	float precision;
	float recalll;
};

