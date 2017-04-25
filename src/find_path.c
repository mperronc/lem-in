/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 11:17:48 by mperronc          #+#    #+#             */
/*   Updated: 2017/04/25 15:37:08 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lemin.h"

static t_room	*pick_min(t_room *cur, int status)
{
	int		i;
	t_room	*min;

	min = NULL;
	i = 0;
	while (cur->adjs[i])
	{
		if (cur->adjs[i]->type == START)
			return (cur->adjs[i]);
		if (cur->adjs[i]->used == status)
		{
			if (!min || cur->adjs[i]->weight < min->weight)
				min = cur->adjs[i];
		}
		i++;
	}
	return (min);
}

static t_room	*pick_next(t_room *cur, int *flag)
{
	t_room	*next;

	if (*flag == 0)
	{
		next = pick_min(cur, FREE);
		if (!next)
			*flag = 1;
	}
	if (*flag == 1)
		next = pick_min(cur, USED);
	return (next);
}

t_room			**find_path(t_room *end, t_hex *hex)
{
	t_room	*crawl;
	t_room	**path;
	int		i;
	int		flag;

	path = init_rooms(hex);
	crawl = end;
	path[0] = crawl;
	i = 1;
	flag = FREE;
	while (crawl && crawl->type != START)
	{
		crawl = pick_next(crawl, &flag);
		if (crawl != NULL)
		{
			crawl->used = 1;
			path[i] = crawl;
			i++;
		}
	}
	if (crawl && crawl->type == START)
		return (path);
	else
		return (NULL);
}
