#include "../so_long.h"

void key_handle(int dir, char **map)
{
	dir = move(dir, map);
	if (dir)
		update_image(dir, map);
}

int main(int argc, char **argv)
{
	t_all all;

	if (!is_valid_args(argc, argv, &all.err))
		ft_error(all.err);
	all.map = make_map(argv[1], &all.err);
	if (all.map.map == NULL)
		ft_error(all.err);
	if (!is_valid_map(all.map, &all.err))
		ft_error(all.err);
	make_screen();
	make_image();
	while (1)
	{
		hook();
	}
}
