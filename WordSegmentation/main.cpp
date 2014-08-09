#include "head.h"
#include "ArithmeticFactory.h"
#include "SegmentationArithmetic.h"
extern char allSymbols[] = {
//Сд��ĸ26
'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 
//��д��ĸ26
'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 
//����10
'1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
//Ӣ�ı�����30
'!','\\','*','(',')','-','_','+','=','{','}','[',']',':',';','\"','\"',',','<','>','.','?','/','|','@','#','$','%','^','&',
//���ı����Ų���Ҫ���ǣ���Ϊ���ı��ռ���ַ����Ҳ�������ɴ�
//'��', '��', '��', '��', '��', '��', '��', '��', '��', '��', '��', '��', '��', '��', '��', '��', '��', '|', '��', '��', '��', '��'
};

void main()
{
	cout<<"begin split segmentation...."<<endl;


	clock_t start, finish;
	double duration;
	start = clock();
	ArithmeticFactory factory ;

	SegmentationArithmetic * split_arith = factory.createArithmetic(1);
	
	string str_preprocessed = "���ķִ��㷨��20����80���������һֱ��һ���о��ȵ㡣���������������ڶ�ѧ�������ķִ��������˴���������ȡ����һ�����о��ɹ���";
	string standard_segment ="����/�ִ�/�㷨/��/20/����/80/���/����/��/һֱ/��/һ��/�о�/�ȵ�/��/������/��/������/�ڶ�/ѧ��/��/����/�ִ�/����/����/����/����/��/ȡ��/��/һ����/�о�/�ɹ�/��";
	
	split_arith->setStandardSplitSegment(standard_segment);
	split_arith->setSourceSegment(str_preprocessed);

	split_arith->splitSourceSegment();
	
	split_arith->createOutFile();
	
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout<<"calculate time:"<<duration<<"(seconds)"<<endl;

	cout<<"end splint segmentation....."<<endl;

	system("pause");

	delete split_arith;
	split_arith=NULL;

	return ;
}