/* 42 Header Here */

#include "../incl/lem-in.h"

int	main(void)
{
	char	*map;
	t_hex	*hex;
	t_room ***paths;

	map = read_map();
	hex = parse_map(map);
	weigh_edges(hex->rooms);
	ft_printf("Looking for Paths...\n");
	paths = find_paths(hex);
	print_paths(paths);
}
