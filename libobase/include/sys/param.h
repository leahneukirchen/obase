#ifndef OBASE_PARAM_H
#define OBASE_PARAM_H

#include <sys/types.h>

#define UID_MAX UINT_MAX
#define GID_MAX UINT_MAX
#define MAXBSIZE (64 * 1024)
#define NOFILE_MAX 1024
#define NOFILE 256
#define CHILD_MAX 1024
#define MAXLOGNAME 31
#define NGROUPS NGROUPS_MAX

// XXX amd64 only
#define ALIGNBYTES      (sizeof(long) - 1)
#define ALIGN(p)        (((u_int)(p) + ALIGNBYTES) &~ ALIGNBYTES)

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define howmany(x,y) (((x)+((y)-1))/(y))

static char* __progname = "unknown";

#include_next <sys/param.h>

#endif
