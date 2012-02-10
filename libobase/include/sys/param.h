#define UID_MAX UINT_MAX
#define GID_MAX UINT_MAX
#define MAXBSIZE (64 * 1024)
#define NOFILE_MAX 1024
#define MAXLOGNAME 31

// XXX amd64 only
#define ALIGNBYTES      (sizeof(long) - 1)
#define ALIGN(p)        (((u_int)(p) + ALIGNBYTES) &~ ALIGNBYTES)

#include_next <sys/param.h>
