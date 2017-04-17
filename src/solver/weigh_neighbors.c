/* 42 HEADER HERE */

#include "../incl/lem-in.h"

void	weigh_neighbors(t_room *cur)
{
	int		i;

	i = 0;
	while (cur->adjs[i])
	{
		if (cur->adjs[i]->weight == -1 || cur->adjs[i]->weight > cur->weight)
			cur->adjs[i]->weight = cur->weight + 1;
		i++;
	}
}
