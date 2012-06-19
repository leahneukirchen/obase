#include <sys/types.h>
#include <grp.h>
#include <pwd.h>

/* Ignore stayopen.  */

int
setpassent(int stayopen)
{
	setpwent();
	return 1;
}

int
setgroupent(int stayopen)
{
	setgrent();
	return 1;
}
