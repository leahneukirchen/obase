#include_next <stddef.h>

void *memrchr(const void *b, int c, size_t len);
char *strcasestr(const char *big, const char *little);
size_t strlcpy(char *dst, const char *src, size_t size);
size_t strlcat(char *dst, const char *src, size_t size);

#include_next <string.h>
