/* 42 Header */

#include "lem-in.h"

t_room		**allocate_rooms(char **split_map)
{
	int		n_rooms;
	int		map_i;
	t_room	**rooms;

	n_rooms = 0;
	map_i = 1;

	while (split_map[map_i])
	{
		if (split_map[map_i][0] != '#' && ft_strchr(split_map[map_i], ' '))
			n_rooms += 1;
		map_i += 1;
	}

	rooms = (t_room **)malloc(sizeof(t_room *) * n_rooms + 1);
	return (rooms);
}
