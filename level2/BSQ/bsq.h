#ifndef BSQ_H
#define BSQ_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/errno.h>

typedef struct {
	int		height, width;
	char	empty, obstacle, full;
}meta;

typedef struct {
	int**	db;
	int size, i, j;
}data;

typedef struct {
	char**	map;
	meta	info;
	data	solve;
}bsq;

#endif