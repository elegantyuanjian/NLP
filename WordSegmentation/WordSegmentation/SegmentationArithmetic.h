#pragma once
#include "head.h"


class SegmentationArithmetic
{
public:
	SegmentationArithmetic(void);
	~SegmentationArithmetic(void);
	
	/**�ѷִʽ�������ָ�����ļ���**/
    bool createOutFile();

	string preProcess(string source_segment);

	void setSourceSegment(string source_segment);

	void setStandardSplitSegment(string standard_segment);

	void setSymbols();

	/**��ԭʼ�ַ���������ָ�����㷨���зִ�
	 * ÿ����֮�����ַ�'/'��Ϊ����
	 */
	virtual void splitSourceSegment() = 0;

private:
	
	/**��׼�������ַ���**/
	string standard_segment;

	/**Ԥ����ǰ���ַ���*/
	string beforprecess_segment;
	/**ԭʼ�ַ���**/
	string source_segment;

	/**ԭʼ�ַ����ִʹ�����ַ���**/
	string result_segment;
	
	//�洢ԭʼ�ַ����е�Ӣ�ĵ��ʺͱ����ŵȷ������ַ�
	list<string> symbols;

	set<char> symbolset;

protected:

	Word_Dictionary_Map * word_dictionary_map;
	int loadDict();
	string getSourceSegment();
	string getResultSegment();
	void setResultSegment(string resultsegment);
	string getFirstSymbol();
};

