#define _PW_NAME_LEN 31
#define _PATH_MP_DB "/dev/null"

#include_next <pwd.h>

int setpassent(int stayopen);
int setgroupent(int stayopen);
const char *user_from_uid(uid_t uid, int nouser);
const char *group_from_gid(gid_t gid, int nogroup);
