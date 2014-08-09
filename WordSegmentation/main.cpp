#include "head.h"
#include "ArithmeticFactory.h"
#include "SegmentationArithmetic.h"
extern char allSymbols[] = {
//小写字母26
'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 
//大写字母26
'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 
//数字10
'1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
//英文标点符号30
'!','\\','*','(',')','-','_','+','=','{','}','[',']',':',';','\"','\"',',','<','>','.','?','/','|','@','#','$','%','^','&',
//中文标点符号不需要考虑，因为中文标点占两字符，且不可能组成词
//'“', '”', '，', '。', '、', '！', '？', '《', '》', '：', '‘', '’', '；', '【', '】', '｛', '｝', '|', '—', '·', '（', '）'
};

void main()
{
	cout<<"begin split segmentation...."<<endl;


	clock_t start, finish;
	double duration;
	start = clock();
	ArithmeticFactory factory ;

	SegmentationArithmetic * split_arith = factory.createArithmetic(1);
	
	string str_preprocessed = "中文分词算法从20世纪80年代以来就一直是一个研究热点。近年来，国内外众多学者在中文分词领域做了大量工作，取得了一定的研究成果。";
	string standard_segment ="中文/分词/算法/从/20/世纪/80/年代/以来/就/一直/是/一个/研究/热点/。/近年来/，/国内外/众多/学者/在/中文/分词/领域/做了/大量/工作/，/取得/了/一定的/研究/成果/。";
	
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