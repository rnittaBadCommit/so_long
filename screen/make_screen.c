#include "../so_long.h"

void set_resolution(t_resolution *resolution, map map)
{
	resolution->y = map.height * BLOCK_SIZE;
	resolution->x = map.width * BLOCK_SIZE;
}



void convert_map2image();

void make_image(t_display *display, map map)
{
	_set_resolution(display->resolution, map);

}
