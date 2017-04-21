/* 42 HEADER HERE */

#include "../../incl/lem-in.h"

void	weigh_edges(t_room **rooms)
{
	t_room *cur;

	cur = lookup_start(rooms);
	cur->weight = 0;
	while (cur != NULL)
	{
		weigh_neighbors(cur);
		cur->visited = 1;
		cur = select_next(rooms);
	}
}
