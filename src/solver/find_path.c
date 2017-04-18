/* 42 HEADER HERE */

#include "../../incl/lem-in.h"

static t_room *pick_next(t_room *cur)
{
	int i;

	i = 0;
	while (cur->adjs[i])
	{
		if (cur->adjs[i]->weight < cur->weight)
			return (cur->adjs[i]);
		i++;
	}
	return NULL;
}

void find_path(t_room *start)
{
	t_room	*crawl;

	crawl = start;
	ft_printf("%s -> ", crawl->name);
	while (crawl->type != END)
	{
		crawl = pick_next(crawl);
		if (crawl)
			ft_printf("%s -> ", crawl->name);
	}
	ft_printf("END\n");
}
