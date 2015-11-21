/*
 * streams.c
 *
 *  Created on: Nov 17, 2015
 *      Author: root
 */

#include <stdio.h>
#include <unistd.h>

size_t readLine(int fd, char* line, size_t len) {
	if (len >= 1) line[0] = 0;
	char b = 0;
	int s = 0;
	int i = 0;
	do {
		s = read(fd, &b, 1);
		if ((s == 0 && i == 0) || s < 0) {
			return -1;
		}
		if (s > 0 && b != 13 && b != 10) {
			line[i++] = b;
		}
	} while (b > -1 && s > 0 && b != 10 && i < len - 1);
	line[i] = 0;
	return i;
}

size_t writeLine(int fd, char* line, size_t len) {
	int i = 0;
	while (i < len) {
		int x = write(fd, line + i, len + 1 - i);
		if (x < 0) return -1;
		i += x;
	}
	return i;
}
