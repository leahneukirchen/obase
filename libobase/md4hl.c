/*	$OpenBSD: helper.c,v 1.9 2010/01/08 13:30:21 oga Exp $	*/

/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <phk@login.dkuug.dk> wrote this file.  As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return.   Poul-Henning Kamp
 * ----------------------------------------------------------------------------
 */

#include <sys/param.h>
#include <sys/stat.h>

#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <md4.h>

/* ARGSUSED */
char *
MD4End(MD4_CTX *ctx, char *buf)
{
	int i;
	u_int8_t digest[MD4_DIGEST_LENGTH];
	static const char hex[] = "0123456789abcdef";

	if (buf == NULL && (buf = malloc(MD4_DIGEST_STRING_LENGTH)) == NULL)
		return (NULL);

	MD4Final(digest, ctx);
	for (i = 0; i < MD4_DIGEST_LENGTH; i++) {
		buf[i + i] = hex[digest[i] >> 4];
		buf[i + i + 1] = hex[digest[i] & 0x0f];
	}
	buf[i + i] = '\0';
	memset(digest, 0, sizeof(digest));
	return (buf);
}

char *
MD4FileChunk(const char *filename, char *buf, off_t off, off_t len)
{
	struct stat sb;
	u_char buffer[BUFSIZ];
	MD4_CTX ctx;
	int fd, save_errno;
	ssize_t nr;

	MD4Init(&ctx);

	if ((fd = open(filename, O_RDONLY)) < 0)
		return (NULL);
	if (len == 0) {
		if (fstat(fd, &sb) == -1) {
			close(fd);
			return (NULL);
		}
		len = sb.st_size;
	}
	if (off > 0 && lseek(fd, off, SEEK_SET) < 0) {
		close(fd);
		return (NULL);
	}

	while ((nr = read(fd, buffer, MIN(sizeof(buffer), len))) > 0) {
		MD4Update(&ctx, buffer, (size_t)nr);
		if (len > 0 && (len -= nr) == 0)
			break;
	}

	save_errno = errno;
	close(fd);
	errno = save_errno;
	return (nr < 0 ? NULL : MD4End(&ctx, buf));
}

char *
MD4File(const char *filename, char *buf)
{
	return (MD4FileChunk(filename, buf, (off_t)0, (off_t)0));
}

char *
MD4Data(const u_char *data, size_t len, char *buf)
{
	MD4_CTX ctx;

	MD4Init(&ctx);
	MD4Update(&ctx, data, len);
	return (MD4End(&ctx, buf));
}
