#include "../so_long.h"

void zero_reset(void *a, void *b,void *c, void *d)
{
	if (a != NULL)
		*(int *)a = 0;
	if (b != NULL)
		*(int *)b = 0;
	if (c != NULL)
		*(int *)c = 0;
	if (d != NULL)
		*(int *)d = 0;
}
