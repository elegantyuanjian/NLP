#pragma once
#include "head.h"


class SegmentationArithmetic
{
public:
	SegmentationArithmetic(void);
	~SegmentationArithmetic(void);
	
	/**把分词结果输出到指定的文件中**/
    bool createOutFile();

	string preProcess(string source_segment);

	void setSourceSegment(string source_segment);

	void setStandardSplitSegment(string standard_segment);

	void setSymbols();

	/**把原始字符串，经过指定的算法经行分词
	 * 每个词之间用字符'/'作为区分
	 */
	virtual void splitSourceSegment() = 0;

private:
	
	/**标准处理后的字符串**/
	string standard_segment;

	/**预处理前的字符串*/
	string beforprecess_segment;
	/**原始字符串**/
	string source_segment;

	/**原始字符串分词过后的字符串**/
	string result_segment;
	
	//存储原始字符串中的英文单词和标点符号等非中文字符
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

