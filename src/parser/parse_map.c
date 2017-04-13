/* 42 Header */

#include "../incl/lem-in.h"

t_hex	*parse_map(char *map)
{
	char	**split_map;
	t_hex   *hex;

	hex = (t_hex *)malloc(sizeof(t_hex));

	split_map = ft_strsplit(map, '\n');
	for (int i = 0; split_map[i] != 0; i++) {
		printf("%d : %s\n", i, split_map[i]);
	}

	hex->ants = get_ants(split_map[0]);
	printf("There is %d ants in the map\n", hex->ants);

	hex->rooms = make_rooms(split_map);

	int i = 0;

	while (hex->rooms[i])
	{
		puts(hex->rooms[i]->name);
		i++;
	}

	// print_rooms(hex);

	return (hex);
}
