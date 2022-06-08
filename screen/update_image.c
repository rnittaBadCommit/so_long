#include "../so_long.h"

static void    _set_block_process(t_image back_image, t_image texture, t_pos pos)
{
    void            *dest;
    unsigned int    color;
    int _y;
    int _x;

    _y = 0;
    while (_y < BLOCK_SIZE)
    {
        _x = 0;
        while (_x < BLOCK_SIZE)
        {
            color = get_color(texture, _y, _x);
            if (color != rgb2int(255, 255, 255))
            {
                dest = get_addr_of_pixel(back_image, pos.y * BLOCK_SIZE + _y, pos.x * BLOCK_SIZE + _x);
                *(unsigned int *)dest = color;
            }
            _x++;
        }
        _y++;
    }
}

void    _set_block(t_display display, char map_value, t_pos pos)
{
    if (map_value == '0')
        _set_block_process(display.back_img, display.ground, pos);
    else if (map_value == '1')
        _set_block_process(display.back_img, display.wall, pos);
    else 
    {
        _set_block_process(display.back_img, display.ground, pos);
        if (map_value == 'C')
            _set_block_process(display.back_img, display.collect, pos);
        else if (map_value == 'E')
            _set_block_process(display.back_img, display.exit, pos);
        else if (map_value == 'P')
            _set_block_process(display.back_img, display.player, pos);
    }
}

void    update_image(t_display display, t_map map, t_pos previous_pos, t_pos current_pos)
{
    _set_block(display, map.map[previous_pos.y][previous_pos.x], previous_pos);
    _set_block(display, map.map[current_pos.y][current_pos.x], current_pos);
}

void	set_image(t_display display, t_map map)
{
	t_pos pos;

	pos.y = 0;
	while (pos.y < map.height)
	{
		pos.x = 0;
		while (pos.x < map.width)
		{
			_set_block(display, map.map[pos.y][pos.x], pos);
			pos.x++;
		}
		pos.y++;
	}
}
