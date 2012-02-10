#include <unistd.h>
#include_next <stdlib.h>
#include_next <stddef.h>

u_int32_t arc4random(void);
void arc4random_buf(void *buf, size_t nbytes);
u_int32_t arc4random_uniform(u_int32_t upper_bound);
void arc4random_stir(void);
void arc4random_addrandom(unsigned char *dat, int datlen);
int mkstemp(char *template);
long long strtonum(const char *nptr, long long minval, long long maxval, const char **errstr);
