#include "../so_long.h"

int		rgb2int(double *rgb)
{
	int r;
	int g;
	int b;

	if ((r = (int)rgb[0]) >= 255)
		r = 255;
	if ((b = (int)rgb[2]) >= 255)
		b = 255;
	if ((g = (int)rgb[1]) >= 255)
		g = 255;
	if (r < 0)
		r = 0;
	if (b < 0)
		b = 0;
	if (g < 0)
		g = 0;
	return (r * pow(2, 16) + g * pow(2, 8) + b);
}
