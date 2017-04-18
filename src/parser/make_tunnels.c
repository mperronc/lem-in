/* 42 HEADER Here */

#include "../../incl/lem-in.h"

void make_tunnels(t_hex *hex, char **split_map)
{
	int	map_i;

	map_i = 0;
	while (split_map[map_i])
	{
		if (ft_strchr(split_map[map_i], '#') == 0 && ft_strchr(split_map[map_i], '-') != 0)
		{
			make_tunnel(hex, split_map[map_i]);
		}
		map_i++;
	}
}
