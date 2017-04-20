/* 42 HEADER HERE */

#include "../../incl/lem-in.h"

static t_room *pick_min(t_room *cur)
{
	int		i;
	t_room	*min;

	min = NULL;
	i = 0;
	while (cur->adjs[i])
	{
		if (!min || cur->adjs[i]->weight < min->weight)
			min = cur->adjs[i];
		i++;
	}
	return (min);
}

static t_room *pick_next(t_room *cur)
{
	// From END only choose not used
	// Then choose min not used
	// if nothing choose min used, flag on used path set to 1
	// follow used until start
	// repeat until all rooms directly adjacent to end are used
	t_room	*next;

	next = pick_min(cur);
	return (next);
}

t_room	**find_path(t_room *start, t_hex *hex)
{
	t_room	*crawl;
	t_room	**path;
	int		i;

	path = init_rooms(hex);
	crawl = start;
	path[0] = crawl;
	i = 1;
	while (crawl && crawl->type != END)
	{
		print_room(crawl);
		crawl = pick_next(crawl);
		if (crawl != NULL)
		{
			path[i] = crawl;
			i++;
		}
	}
	if (crawl && crawl->type == END)
		return (path);
	else
		return (NULL);
}
