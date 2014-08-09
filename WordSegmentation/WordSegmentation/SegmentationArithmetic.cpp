#include "SegmentationArithmetic.h"
#include "DataConvertor.h"
#include "head.h"
#include "EvaluateSystem.h"

extern char allSymbols[];

SegmentationArithmetic::SegmentationArithmetic(void)
{
}


SegmentationArithmetic::~SegmentationArithmetic(void)
{

}

void SegmentationArithmetic::setSymbols()
{
	int i;
	for(i = 0; i < 92; i++)
		symbolset.insert(allSymbols[i]);
}

//Ԥ������ԭʼ�ַ����е�Ӣ�ĵ��ʺͱ����ŵ������ַ���ʱ��'##'�滻
//�����滻���ķ��Ŵ洢��symbols���list��
string SegmentationArithmetic::preProcess(string source_segment)
{
	setSymbols();
	int lengthofsource = source_segment.size();
	int tempcount = 0;
	string temp;
	for(int i = 0; i < lengthofsource; ){
		while( symbolset.count(source_segment[i]) ){
			tempcount++;
			i++;
		}
		if(!tempcount)
			i++;
		else{
			temp = source_segment.substr(i-tempcount, tempcount);
			symbols.push_back(temp);
			source_segment.replace(i-tempcount, tempcount, "##");
			lengthofsource = lengthofsource - tempcount + 2;
			i = i - tempcount + 2;
		}
		tempcount = 0;
	}
	return source_segment;
}

//����ʵ䣬���õ��ʵ��дʵ���󳤶�
int SegmentationArithmetic::loadDict()
{
	word_dictionary_map = new Word_Dictionary_Map();
	DataConvertor * dataconvertor = new DataConvertor();
	dataconvertor->convertDictionary(word_dictionary_map);
	delete dataconvertor;
	return MAX_WORD_LENGTH;
}


void SegmentationArithmetic::setSourceSegment(string sourcesegment)
{
	this->beforprecess_segment = sourcesegment;

	this->source_segment= this->preProcess(sourcesegment);
}

void SegmentationArithmetic::setStandardSplitSegment(string stardardsplitsegment)
{
	this->standard_segment = stardardsplitsegment;
}

bool SegmentationArithmetic::createOutFile()
{
	ofstream ouf;
	ouf.open(RESULT_PATH,ios::out);
	if(this->result_segment=="")
	{
		return false;
	}
	else
	{
		//����ִʽ��
		ouf<<"�ִ�ǰ���ַ���Ϊ:"<<endl;
		ouf<<this->beforprecess_segment<<endl;
		ouf<<"�ִʺ���ַ���Ϊ��"<<endl;
		ouf<<this->result_segment<<endl;
		ouf<<"��׼�ִ��ַ���Ϊ��"<<endl<<this->standard_segment<<endl;

		ouf<<"���ֽ��Ϊ"<<endl;
		EvaluateSystem * evaluate = new EvaluateSystem();
		evaluate->setSystemResult(this->result_segment);

		evaluate->setSystemStandard(this->standard_segment);

		evaluate->setParam();
		ouf<<"��ȷ��Ϊ"<<endl;
		ouf<<evaluate->getPrecision()<<endl;
		ouf<<"�ٻ���Ϊ"<<endl;
		ouf<<evaluate->getRecall()<<endl;
		ouf<<"F-MeasureֵΪ"<<endl;
		ouf<<evaluate->getFMeasure();

		delete evaluate;
		return true;
	}
}

string SegmentationArithmetic::getSourceSegment()
{
	return this->source_segment;
}
string SegmentationArithmetic::getResultSegment()
{
	return this->result_segment;
}

void SegmentationArithmetic::setResultSegment(string resultsegment)
{
	this->result_segment = resultsegment;
}

string SegmentationArithmetic::getFirstSymbol()
{
	string temp;
	if(symbols.size() != 0){
		temp = symbols.front();
		symbols.pop_front();
	}
	return temp;
}