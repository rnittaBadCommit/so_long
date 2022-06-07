#include "../so_long.h"

void move_main(t_all *all, int dir)
{
	dir = move(dir, &all->me, all->map.map);
	if (dir != NO_MOVE)
	{
		update_image(all->map, all->me.previous_pos, all->me.current_pos, all->display);
		update_screen(&all->display);
		update_map();
	}
}

int main(int argc, char **argv)
{
	t_all all;

	if (!is_valid_args(argc, argv, &all.err))
		ft_error(all.err);
	all.map = make_map(argv[1], &all.err);
	if (all.map.map == NULL)
		ft_error(all.err);
	if (!is_valid_map(all.map.map, &all.err))
		ft_error(all.err);
	screen_main(all);
}
