#pragma once
#include "segmentationarithmetic.h"
#include "head.h"
/**
 * 正向匹配最大算法
 */
class MMSegmentation :public SegmentationArithmetic
{
public:
	MMSegmentation(void);
	~MMSegmentation(void);
	
	//实现分词
	void splitSourceSegment();

	

private :

	//返回截取后的字符串的长度
	int splitSourceSegment(string source);

	/*matchstring 匹配字典中的字**/
	bool matchSegment(string matchstring);

	//生成结果
	void makeResult();

	Word_Dictionary_Map * word_dictionary_map;
	string source_segment;
	Result_Segment_List * result_segment_list;

};

