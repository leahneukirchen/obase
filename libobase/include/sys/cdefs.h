#ifndef __FBSDID
# define __FBSDID(x)
#endif

#define __dead          __attribute__((__noreturn__))
#define __pure          __attribute__((__const__))
#define __weak_alias(alias,sym)                                 \
        __asm__(".weak " __STRING(alias) " ; " __STRING(alias)  \
            " = " __STRING(sym))

#include_next <sys/cdefs.h>
