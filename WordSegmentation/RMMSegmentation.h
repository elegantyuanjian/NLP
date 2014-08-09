#pragma once
#include "segmentationarithmetic.h"
#include "head.h"
/**
 * ����ƥ������㷨
 */
class RMMSegmentation :public SegmentationArithmetic
{
public:
	RMMSegmentation(void);
	~RMMSegmentation(void);
	//ʵ�ִַ�
	void splitSourceSegment();

private :

	//���ؽ�ȡ����ַ����ĳ���
	int splitSourceSegment(string sourcesegment);

	//matchstring ƥ���ֵ��е���
	bool matchSegment(string matchstring);

	//���ɽ��
	void makeResult();

	string source_segment;
	
	Result_Segment_List * result_segment_list;
};

