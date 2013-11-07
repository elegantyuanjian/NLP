#include "MMSegmentation.h"
#include "DataConvertor.h"

MMSegmentation::MMSegmentation(void)
{
	//��ȡ��Ҫ���зֵ��ַ���
	
}


MMSegmentation::~MMSegmentation(void)
{
	delete word_dictionary_map;
	delete result_segment_list;
}

void MMSegmentation::splitSourceSegment()
{
	source_segment= getSourceSegment();
	
	//��ȡ�ֵ�
	word_dictionary_map = new Word_Dictionary_Map();
	DataConvertor * dataconvertor = new DataConvertor();
	dataconvertor->convertDictionary(word_dictionary_map);

	result_segment_list = new Result_Segment_List();
	int wordlength = dataconvertor->getMaxWordLength();
	delete dataconvertor;
	
	int segmentlenth = this->source_segment.length();
	string source = this->source_segment;
	int begin=0;
	for(int i = 0 ; i < segmentlenth ; )
	{
		string temp = source.substr(i,wordlength);
		int returnlength = splitSourceSegment(temp);		
		i = returnlength +i;	
	}
	makeResult();
}

int MMSegmentation::splitSourceSegment(string sourcesegment)
{
	string temp  =  sourcesegment;
	int length = sourcesegment.length();
	//�����ַ�����Ϊ2 
	if(length <= 2)
	{
		this->result_segment_list->push_back(temp);
		//����
		return temp.length();
	}
	else
	{
		if(matchSegment(temp))
		{
			this->result_segment_list->push_back(temp);
			//����
			return temp.length();
		}
		else
		{
			return splitSourceSegment(temp.substr(0,length-2));
		}
	}
}

//ƥ���ַ�
bool MMSegmentation::matchSegment(string matchstring)
{
	int length = matchstring.length();
	if(length <= 2)
	{
		return true;
	}
	else
	{
		Word_Dictionary_Map::iterator iterator;
		
		for(iterator = this->word_dictionary_map->begin(); iterator != this->word_dictionary_map->end(); iterator++)
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



void MMSegmentation::makeResult()
{
	//�õ��ִʽ����
	Result_Segment_List::iterator iterator;
	string temp = "";
	string temp1 = "";
	for(iterator = this->result_segment_list->begin(); iterator != this->result_segment_list->end();iterator++)
	{
		//�ַ��滻
		temp1 = * iterator;
		if(temp1=="##")
		{
			temp1 = this->getFirstSymbol();
		}
		if(iterator==this->result_segment_list->begin())
		{
			temp = * iterator ;
			
		}
		else
		{
			temp = temp+"/"+temp1;
	
		}
	}
	this->setResultSegment(temp);

	
}