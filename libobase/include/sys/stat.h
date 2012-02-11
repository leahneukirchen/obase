#include_next <sys/stat.h>
#include_next <sys/statfs.h>
#include_next <sys/param.h>

#define st_atimespec st_atim
#define st_mtimespec st_mtim
#define st_atimensec st_atim.tv_nsec
#define st_ctimensec st_ctim.tv_nsec
#define st_mtimensec st_mtim.tv_nsec
#define f_iosize f_bsize

#define DEFFILEMODE (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)/* 0666*/
