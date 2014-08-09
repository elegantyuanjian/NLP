#pragma once
#include "segmentationarithmetic.h"
#include "head.h"
/**
 * ����ƥ������㷨
 */
class MMSegmentation :public SegmentationArithmetic
{
public:
	MMSegmentation(void);
	~MMSegmentation(void);
	
	//ʵ�ִַ�
	void splitSourceSegment();

	

private :

	//���ؽ�ȡ����ַ����ĳ���
	int splitSourceSegment(string source);

	/*matchstring ƥ���ֵ��е���**/
	bool matchSegment(string matchstring);

	//���ɽ��
	void makeResult();

	Word_Dictionary_Map * word_dictionary_map;
	string source_segment;
	Result_Segment_List * result_segment_list;

};

