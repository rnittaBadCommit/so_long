#include "../../so_long.h"

void    *get_addr_of_pixel(t_image *img, int y, int x)
{
    return (img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8)));
}

// void    *get_addr_of_block(t_image *img, t_pos pos)
// {
//     void    *dst;

//     dst = get_addr_of_pixel(img, pos.y * BLOCK_SIZE, pos.x * BLOCK_SIZE);
//     return (dst);
// }

unsigned int		rgb2int(int r, int g, int b)
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
	//printf("call get_addr_of_pixel from get_color\n");
	//printf("%p\n", img->addr);
	return (*(unsigned int *)get_addr_of_pixel(img, y, x));
}

void	*my_mlx_get_data_addr(t_image *img)
{
	return (mlx_get_data_addr(&img->img, &img->bits_per_pixel, &img->line_length, &img->endian));
}