#pragma once
#include "SegmentationArithmetic.h" 
class ArithmeticFactory
{
public:
	ArithmeticFactory(void);
	~ArithmeticFactory(void);
	/**�����ִʷ�����**/

	SegmentationArithmetic * createArithmetic(int type_arithmetic);
};

