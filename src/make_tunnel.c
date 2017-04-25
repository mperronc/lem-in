/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tunnel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 11:17:16 by mperronc          #+#    #+#             */
/*   Updated: 2017/04/25 12:28:27 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lemin.h"

static void	add_room(t_room **list, t_room *room)
{
	int i;

	i = 0;
	while (list[i] != NULL)
		i++;
	list[i] = room;
}

static int	not_dup(t_room *r1, t_room *r2)
{
	return (!lookup_room(r1->adjs, r2->name)
			&& !lookup_room(r2->adjs, r2->name));
}

static void	connect(t_room *room1, t_room *room2)
{
	add_room(room1->adjs, room2);
	add_room(room2->adjs, room1);
}

void		make_tunnel(t_hex *hex, char *line)
{
	char	**sline;
	t_room	*room1;
	t_room	*room2;

	sline = ft_strsplit(line, '-');
	room1 = lookup_room(hex->rooms, sline[0]);
	room2 = lookup_room(hex->rooms, sline[1]);
	if (room1 && room2 && not_dup(room1, room2))
		connect(room1, room2);
	free_tab(sline);
}
