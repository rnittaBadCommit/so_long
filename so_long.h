#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "./ft_malloc/ft_malloc.h"

#define MAP_SIZE_MAX 1 << 30
typedef char **map;
typedef struct s_me
{
	int y;
	int x;
} t_me;

typedef enum
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	NO_MOVE,
} e_dir;

typedef enum
{
	TOO_LARGE_MAP,
	NOT_RECTANGLE,
	INVALID_CHAR,
	INVALID_CHAR_NUM,
	NOT_CLOSED_MAP,
	NO_ERR,
} e_err;

typedef struct s_all
{
	t_me me;
	char **map;
	e_err err;
} t_all;

#endif
