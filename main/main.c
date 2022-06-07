#include "../so_long.h"

void	finalize(t_all *all)
{
	ft_exit(all);
}

int main(int argc, char **argv)
{
	t_all all;

	if (!is_valid_args(argc, argv, &all.err))
		ft_error(all);
	all.map = make_map(argv[1], &all.err);
	if (all.map.map == NULL)
		ft_error(all);
	if (!is_valid_map(all.map.map, &all.err))
		ft_error(all);
	screen_main(all, all.display);
}
