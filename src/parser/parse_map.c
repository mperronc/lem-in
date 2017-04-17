/* 42 Header */

#include "../incl/lem-in.h"

t_hex	*parse_map(char *map)
{
	char	**split_map;
	t_hex   *hex;

	hex = (t_hex *)malloc(sizeof(t_hex));

	split_map = ft_strsplit(map, '\n');

	hex->ants = get_ants(split_map[0]);
	hex->rooms = make_rooms(split_map);
	make_tunnels(hex, split_map);

	return (hex);
}
