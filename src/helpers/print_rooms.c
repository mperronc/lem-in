#include "../../incl/lem-in.h"

void	print_rooms(t_room **rooms)
{
	int i = 0;
	while (rooms[i] != NULL)
	{
		ft_printf("Name : %s\nType : %d\nWeight : %d\n", rooms[i]->name, rooms[i]->type, rooms[i]->weight);
		ft_printf("Connected to :\n");
		print_adj_rooms(rooms[i]);
		i++;
	}
}
