#pragma once
#include "head.h"
class DataConvertor
{
public:
	DataConvertor(void);
	~DataConvertor(void);

	bool convertDictionary(Word_Dictionary_Map * word_dictionary_map);

	int getMaxWordLength();

private:

	int maxwordlength;

};

