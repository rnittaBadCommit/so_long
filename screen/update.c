#include "../so_long.h"

static void _move_back2front(t_display *display)
{
    t_image tmp;

    tmp = display->back_img;
    display->back_img = display->front_img;
    display->front_img = tmp;
}

void    update_screen(t_display *display)
{
    _move_back2front(display);
    mlx_put_image_to_window(display->mlx, display->mlx_win, display->front_img.img, 0, 0);
}