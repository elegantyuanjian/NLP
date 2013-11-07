#include "DataConvertor.h"


DataConvertor::DataConvertor(void)
{
}


DataConvertor::~DataConvertor(void)
{
}


bool DataConvertor::convertDictionary(Word_Dictionary_Map * word_dictionary_map)
{
	ifstream info;
	info.open(DICTIONARY_PATH,ios::in);
	if(!info.is_open())  
    {  
        cout<<"δ�ҵ��ļ�!"<<endl; 
		
		return false ;
    } 

	string word;
	info>>word;

	maxwordlength = word.length();//��ַ���
	
	int index = 0 ;
	while(info.peek() != EOF)
	{		
		word_dictionary_map->insert(Word_Dictionary_VT(index++,word));
		info>>word;
		if(word.length()>maxwordlength)
		{
			maxwordlength= word.length();
		}
	}

	info.close();
	return true ;
}

int DataConvertor::getMaxWordLength()
{
	return this->maxwordlength;
}