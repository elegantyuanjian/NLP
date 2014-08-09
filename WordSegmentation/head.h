#pragma once

#include <string>
#include <fstream>
#include <ostream>
#include <iostream>
#include <list>
#include <map>
#include <time.h>
#include <set>
using namespace std;

/*********************文件路径***************/

#define DICTIONARY_PATH "./sqlet.dict"
//#define DICTIONARY_PATH "./test.txt" 
#define RESULT_PATH "./result.txt"
#define MAX_WORD_LENGTH 6;


typedef map<int,string> Word_Dictionary_Map;
typedef map<int,string>::value_type Word_Dictionary_VT ;
typedef list<string> Result_Segment_List;

//计算时间
#ifndef _CLOCK_T_DEFINED
typedef long clock_t;
#define _CLOCK_T_DEFINED
#endif
#define CLOCKS_PER_SEC ((clock_t)1000)
