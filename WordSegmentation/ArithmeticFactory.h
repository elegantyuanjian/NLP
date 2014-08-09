#pragma once
#include "SegmentationArithmetic.h" 
class ArithmeticFactory
{
public:
	ArithmeticFactory(void);
	~ArithmeticFactory(void);
	/**创建分词方法类**/

	SegmentationArithmetic * createArithmetic(int type_arithmetic);
};

