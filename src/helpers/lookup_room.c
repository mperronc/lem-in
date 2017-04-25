/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 11:16:36 by mperronc          #+#    #+#             */
/*   Updated: 2017/04/25 11:23:52 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/lemin.h"

t_room	*lookup_start(t_room **rooms)
{
	int	i;

	i = 0;
	while (rooms[i])
	{
		if (rooms[i]->type == START)
			return (rooms[i]);
		i++;
	}
	return (NULL);
}

t_room	*lookup_end(t_room **rooms)
{
	int	i;

	i = 0;
	while (rooms[i])
	{
		if (rooms[i]->type == END)
			return (rooms[i]);
		i++;
	}
	return (NULL);
}

t_room	*lookup_room(t_room **rooms, char *name)
{
	int	crawl;

	crawl = 0;
	while (rooms[crawl])
	{
		if (ft_strcmp(rooms[crawl]->name, name) == 0)
			return (rooms[crawl]);
		crawl++;
	}
	return (NULL);
}
