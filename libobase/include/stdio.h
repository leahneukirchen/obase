#define __va_list va_list

#define getline gnu_getline
#include_next <stdio.h>
#undef getline

#include_next <time.h>
