#pragma once
#include "segmentationarithmetic.h"
#include "head.h"
/**
 * 逆向匹配最大算法
 */
class RMMSegmentation :public SegmentationArithmetic
{
public:
	RMMSegmentation(void);
	~RMMSegmentation(void);
	//实现分词
	void splitSourceSegment();

private :

	//返回截取后的字符串的长度
	int splitSourceSegment(string sourcesegment);

	//matchstring 匹配字典中的字
	bool matchSegment(string matchstring);

	//生成结果
	void makeResult();

	string source_segment;
	
	Result_Segment_List * result_segment_list;
};

