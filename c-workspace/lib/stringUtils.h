#ifndef PADDY_STRING_UTILS
#define PADDY_STRING_UTILS

#include "dataStructures.h"

char* concat_string(const char* string1, const char* string2); 

string_list_t* split(char* input, char* delimiter);

void trim(char* input);

char* substring(char* input, int beginning, int end);

#endif