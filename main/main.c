#include "../so_long.h"

char **make_map(char *file_name, e_err *err)
{
	int fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		*err = CANT_OPEN_FILE;
		return (NULL);
	}
	return (read_file(fd, err));
}

int main(int argc, char **argv)
{
	t_all all;

	if (is_valid_args(argc, argv, &all.err))
		ft_error(all.err);
	all.map = make_map(argv[1], &all.err);
	if (all.map == NULL)
		ft_error(all.err);
	if (is_valid_map(all.map, &all.err))
		ft_error(all.err);
	make_screen();
	make_image();
}
