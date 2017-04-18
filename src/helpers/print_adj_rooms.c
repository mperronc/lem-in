#include "../../incl/lem-in.h"

void print_adj_rooms(t_room *room)
{
	int	i;

	i = 0;
	while (room->adjs[i])
	{
		ft_printf("%s ", room->adjs[i]->name);
		i++;
	}
	ft_printf("\n\n");
}
