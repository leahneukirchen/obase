#include <sys/cdefs.h>
#include <sys/stat.h>

#define S_ISTXT S_ISVTX
#define fflagstostr(x) ""

extern int optreset;
#include <getopt.h>
#undef getopt
#define getopt(argc, argv, optstr) bsd_getopt(argc, argv, optstr)
int bsd_getopt(int, char **, char *);

mode_t getmode(const void *set, mode_t mode);
void *setmode(const char *mode_str);

#include_next <unistd.h>
