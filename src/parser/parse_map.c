/* 42 Header */

#include "../../incl/lem-in.h"

static void	init_hex(t_hex *hex)
{
	hex->n_rooms = 0;
	hex->ants = 0;
	hex->rooms = NULL;
	hex->n_paths = 0;
}

t_hex	*parse_map(char **split_map)
{
	t_hex   *hex;

	hex = (t_hex *)malloc(sizeof(t_hex));
	init_hex(hex);
	hex->ants = get_ants(split_map[0]);
	hex->rooms = make_rooms(split_map, hex);
	make_tunnels(hex, split_map);

	return (hex);
}
