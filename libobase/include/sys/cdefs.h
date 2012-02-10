#ifndef __FBSDID
# define __FBSDID(x)
#endif

#define __dead          __attribute__((__noreturn__))
#define __pure          __attribute__((__const__))

#include_next <sys/cdefs.h>
