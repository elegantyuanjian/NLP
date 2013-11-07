#include "RMMSegmentation.h"
#include "DataConvertor.h"

RMMSegmentation::RMMSegmentation(void)
{
}


RMMSegmentation::~RMMSegmentation(void)
{
	delete word_dictionary_map;
	delete result_segment_list;
}

//实现分词
void RMMSegmentation::splitSourceSegment()
{
	source_segment= getSourceSegment();
	result_segment_list = new Result_Segment_List();
	//最大长度
	int wordlength = loadDict();
	int segmentlenth = this->source_segment.length();
	string source = this->source_segment;
	int begin=0;
	for(int i = segmentlenth-1 ; i >= 0 ; )
	{
		string temp;
		if( i < wordlength - 1 ){
			temp = source.substr(0, i+1);	
		}
		else
			temp = source.substr(i-wordlength+1, wordlength);
		int returnlength = splitSourceSegment(temp);
		i = i - returnlength;
	}

	makeResult();
}

//返回截取后的字符串的长度
int RMMSegmentation::splitSourceSegment(string sourcesegment)
{
	string temp  =  sourcesegment;
	int length = sourcesegment.length();
	//中文字符长度为2 
	if(length <= 2)
	{
		this->result_segment_list->push_back(temp);
		//返回
		return temp.length();
	}
	else
	{
		if(matchSegment(temp))
		{
			this->result_segment_list->push_back(temp);
			//返回
			return temp.length();
		}
		else
		{

			return splitSourceSegment(temp.substr(2,length-2));
		}
	}
}


/*matchstring 匹配字典中的字**/
bool RMMSegmentation::matchSegment(string matchstring)
{
	int length = matchstring.length();
	if(length <= 2)
	{
		return true;
	}
	else
	{
		Word_Dictionary_Map::iterator iterator;
		Word_Dictionary_Map::iterator first = this->word_dictionary_map->begin();
		Word_Dictionary_Map::iterator end = this->word_dictionary_map->end();
		for(iterator = first; iterator != end; iterator++)
		{
			string temp = iterator->second;
			if(matchstring == temp)
			{
				return true;
			}
		}
		return false;
	}		
}

//生成结果
void RMMSegmentation::makeResult()
{
	Result_Segment_List::iterator first = this->result_segment_list->begin();
	Result_Segment_List::iterator last = this->result_segment_list->end();
	Result_Segment_List::iterator iterator = --last;
	string temp = *iterator;
	string temp1;
	iterator--;
	for( ; iterator != first; iterator--){
		temp1 = *iterator;
		if( temp1 == "##" ){
			temp1 = this->getFirstSymbol();
		}
		temp = temp+" / "+temp1;
	}
	temp = temp+" / "+*iterator;
	this->setResultSegment(temp);
}