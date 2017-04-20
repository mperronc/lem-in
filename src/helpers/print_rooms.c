#include "../../incl/lem-in.h"

void 	print_room(t_room *room)
{
	ft_printf("Name : %s\nType : %d\nWeight : %d\n", room->name, room->type, room->weight);
	ft_printf("Connected to :\n");
	print_adj_rooms(room);
}

void	print_rooms(t_room **rooms)
{
	int i = 0;
	while (rooms[i] != NULL)
	{
		print_room(rooms[i]);
		i++;
	}
}
