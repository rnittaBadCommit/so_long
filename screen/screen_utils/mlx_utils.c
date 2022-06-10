#include "../../so_long.h"

void	*get_addr_of_pixel(t_image *img, int y, int x)
{
	return (img->data_addr + (y * img->line_length + \
		x * (img->bits_per_pixel / 8)));
}

unsigned int	rgb2int(int r, int g, int b)
{
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	return ((r << 16) + (g << 8) + b);
}

unsigned int	get_color(t_image *img, int y, int x)
{
	return (*(unsigned int *)get_addr_of_pixel(img, y, x));
}

void	*my_mlx_get_data_addr(t_image *img)
{
	return (mlx_get_data_addr(&img->image_addr, &img->bits_per_pixel, \
		&img->line_length, &img->endian));
}
