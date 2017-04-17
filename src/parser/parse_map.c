/* 42 Header */

#include "../incl/lem-in.h"

static void print_adj_rooms(t_room *room)
{
	int	i;

	i = 0;
	while (room->adjs[i])
	{
		printf("%s ", room->adjs[i]->name);
		i++;
	}
	printf("\n\n");
}

t_hex	*parse_map(char *map)
{
	char	**split_map;
	t_hex   *hex;

	hex = (t_hex *)malloc(sizeof(t_hex));

	split_map = ft_strsplit(map, '\n');

	hex->ants = get_ants(split_map[0]);
	hex->rooms = make_rooms(split_map);
	make_tunnels(hex, split_map);

	// DEBUG : PRINTS ROOMS
	int i = 0;
	while (hex->rooms[i] != NULL)
	{
		printf("Room number %d :\nName : %s\nCoords : %d %d\nType : %d\n", hex->rooms[i]->id, hex->rooms[i]->name, hex->rooms[i]->x, hex->rooms[i]->y, hex->rooms[i]->type);
		printf("Connected to :\n");
		print_adj_rooms(hex->rooms[i]);
		i++;
	}
	return (hex);
}
