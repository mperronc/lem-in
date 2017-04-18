/* 42 HEADER HERE */

#include "../../incl/lem-in.h"

t_room	*select_next(t_room *cur)
{
	int		i;
	t_room	*next;

	i = 0;
	next = NULL;
	while (cur->adjs[i])
	{
		if (!cur->adjs[i]->visited && (!next || next->weight > cur->adjs[i]->weight))
			next = cur->adjs[i];
		i++;
	}
	return (next);
}
