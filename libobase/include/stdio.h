#include <sys/cdefs.h>
#include_next <stddef.h>
#include_next <stdint.h>
#include_next <fcntl.h>

#define getline gnu_getline
#include_next <stdio.h>
#undef getline

#define __va_list va_list
int asprintf(char **strp, const char *fmt, ...);
char *fgetln(FILE *stream, size_t *len);

#include_next <time.h>
