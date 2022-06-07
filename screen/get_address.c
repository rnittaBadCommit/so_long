#include "../so_long.h"

void    *get_addr_of_pixel(t_image img, int y, int x)
{
    return (img.addr + (y * img.line_length + x * (img.bits_per_pixel / 8)));
}

void    *get_addr_of_block(t_image img, t_pos pos)
{
    void    *dst;

    dst = get_addr_of_pixel(img, pos.y * BLOCK_SIZE, pos.x * BLOCK_SIZE);
    return (dst);
}