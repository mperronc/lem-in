/* 42 Header Here */

#include "../incl/lem-in.h"

int	main(void)
{
	char	**map;
	t_hex	*hex;
	t_room ***paths;
	t_ant	**ants;

	map = ft_strsplit(read_map(), '\n');

	// map = validate_map(map);

	hex = parse_map(map);

	weigh_edges(hex->rooms);
	paths = find_paths(hex);
	hex->n_paths = filter_paths(paths, hex->ants);
	ants = create_ants(hex);
	simulate(ants, paths, hex->n_paths);
}
