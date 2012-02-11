#ifndef __FBSDID
# define __FBSDID(x)
#endif

#define __dead          __attribute__((__noreturn__))
#define __pure          __attribute__((__const__))
#define __weak_alias(alias,sym)                                 \
        __asm__(".weak " __STRING(alias) " ; " __STRING(alias)  \
            " = " __STRING(sym))

#ifdef  __cplusplus
# define __BEGIN_DECLS  extern "C" {
# define __END_DECLS    }
#else
# define __BEGIN_DECLS
# define __END_DECLS
#endif

#define __CONCAT(x,y)   x ## y
#define __STRING(x)     #x

#define __THROW
