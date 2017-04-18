/* 42 Header Here */

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

static t_room *get_start(t_room **rooms)
{
	int	i;

	i = 0;
	while (rooms[i])
	{
		if (rooms[i]->type == START)
			return (rooms[i]);
		i++;
	}
	// Should not happen
	return (NULL);
}

int	main(void)
{
	char	*map;
	t_hex	*hex;

	map = read_map();
	hex = parse_map(map);
	weigh_edges(hex->rooms);

	int i = 0;
	while (hex->rooms[i] != NULL)
	{
		printf("Name : %s\nType : %d\nWeight : %d\n", hex->rooms[i]->name, hex->rooms[i]->type, hex->rooms[i]->weight);
		printf("Connected to :\n");
		print_adj_rooms(hex->rooms[i]);
		i++;
	}
	find_path(get_start(hex->rooms));
}
