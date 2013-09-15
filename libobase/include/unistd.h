#include <sys/stat.h>
#include <sys/param.h>

#define S_ISTXT S_ISVTX

extern int optreset;
#include <getopt.h>
#undef getopt
#define getopt(argc, argv, optstr) bsd_getopt(argc, argv, optstr)
int bsd_getopt(int, char * const [], const char *);

mode_t getmode(const void *set, mode_t mode);
void *setmode(const char *mode_str);

#define fflagstostr(x) ""
#define issetugid() 0

#include_next <unistd.h>
