/* 42 HEADER HERE */

#include "../../incl/lem-in.h"

static t_room *lookup_end(t_room **rooms)
{
	int	i;

	i = 0;
	while (rooms[i])
	{
		if (rooms[i]->type == END)
			return (rooms[i]);
		i++;
	}
	// Should not happen
	return (NULL);
}

void	weigh_edges(t_room **rooms)
{
	t_room *cur;

	cur = lookup_end(rooms);
	cur->weight = 0;
	while (cur != NULL)
	{
		weigh_neighbors(cur);
		cur->visited = 1;
		cur = select_next(rooms);
	}
}
