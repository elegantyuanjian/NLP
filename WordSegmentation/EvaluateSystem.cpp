#include "EvaluateSystem.h"
#include "head.h"

EvaluateSystem::EvaluateSystem(void)
{
}


EvaluateSystem::~EvaluateSystem(void)
{
}


float EvaluateSystem::getPrecision()
{
	if(system_and_standard==0||system_out==0)
	{
		return 0;
	}
	else
	{
		float up = system_and_standard;
		float down = system_out;
		return (up/down)*100;
	}
}

float EvaluateSystem::getRecall()
{
	if(system_and_standard==0||standard_out==0)
	{
		return 0;
	}
	else
	{
		float up = system_and_standard;
		float down = standard_out;
		return (up/down)*100;
	}
}

float EvaluateSystem::getFMeasure()
{
	this->precision = getPrecision();
	this->recalll = getRecall();
	if(precision==0||recalll==0)
	{
		return 0;
	}
	else
	{
		return ((2*precision*recalll)/(precision+recalll));
	}
}


void EvaluateSystem::setSystemResult(string result)
{
	this->result = result;
}
void EvaluateSystem::setSystemStandard(string standard)
{
	this->stadard = standard;
}


void EvaluateSystem::setParam()
{
	string temp_result = this->result;
	string temp_standard = this->stadard;

	if(temp_result==""||temp_standard=="")
	{
		this->standard_out = 0;
		this->system_out = 0;
		this->system_and_standard = 0;
		
	}

	else
	{
		map<int,string> *result_map = new map<int ,string>();
		map<int,string> *standard_map = new map<int,string>();

		splistSegment(result_map,temp_result);
		splistSegment(standard_map,temp_standard);

		this->system_out = result_map->size();
		
		this->standard_out = result_map->size();

		//º∆À„ΩªºØ
		map<int,string>::iterator result_iterator;
		map<int,string>::iterator standard_iterator;
		int samecount = 0;
		for(result_iterator = result_map->begin();result_iterator!=result_map->end();result_iterator++)
		{
			string temp = result_iterator->second;
			for(standard_iterator = standard_map->begin();standard_iterator!=standard_map->end();standard_iterator++)
			{
				string temp1 = standard_iterator->second;
				if(temp1==temp)
				{
					//this->systemandstandard++;
					samecount ++;
					break;
				}
				
			}

		}
		this->system_and_standard = samecount;
		delete result_map;
		delete standard_map;
	}
	
}

void EvaluateSystem::splistSegment(map<int,string> *result_map,string split_string)
{
	int begin = 0 ;
	int index = 0; 
    int position = 0;

	while((position=split_string.find_first_of('/',index))!=string::npos)
	{
		string temp = split_string.substr(index,position-index);
		
		//position = position +1;
		index=position+1;
		
		result_map->insert(map<int,string>::value_type(begin,temp));
		begin++;
		
	}

	int last = split_string.find_last_of('/');
	
	string temp = split_string.substr(last+1,split_string.length());
	result_map->insert(map<int,string>::value_type(begin,temp));
	
}