#ifndef __FBSDID
# define __FBSDID(x)
#endif

#define __dead          __attribute__((__noreturn__))
#define __pure          __attribute__((__const__))
#define __weak_alias(alias,sym)                                 \
        __asm__(".weak " __STRING(alias) " ; " __STRING(alias)  \
            " = " __STRING(sym))

#define DEFFILEMODE 0666
#define AR_EFMT1 "#1/"

#ifndef EFTYPE
#include <errno.h>
#define EFTYPE EINVAL
#endif

#include <regex.h>
#ifndef REG_STARTEND
#define REG_STARTEND REG_NEWLINE
#endif

