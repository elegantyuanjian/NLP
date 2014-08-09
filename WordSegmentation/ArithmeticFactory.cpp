#include "ArithmeticFactory.h"
#include "MMSegmentation.h"
#include "RMMSegmentation.h"

ArithmeticFactory::ArithmeticFactory(void)
{

}


ArithmeticFactory::~ArithmeticFactory(void)
{

}


SegmentationArithmetic * ArithmeticFactory::createArithmetic(int type_arithmetic)
{
	switch(type_arithmetic)
	{
	case 1:
		return new MMSegmentation();
		break;
	case 2:
		return new RMMSegmentation();
		break;
	}
}