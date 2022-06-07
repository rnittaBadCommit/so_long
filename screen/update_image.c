#include "../so_long.h"

void    set_block(char map_value, void *addr)
{

}

void    update_image(t_map map, t_pos previous_pos, t_pos current_pos, t_image img)
{
    set_block(map.map[previous_pos.y][previous_pos.x], get_addr_of_block(img, previous_pos));
    set_block(map.map[current_pos.y][current_pos.x], get_addr_of_block(img, current_pos));
}