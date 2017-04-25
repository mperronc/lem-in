/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 11:17:10 by mperronc          #+#    #+#             */
/*   Updated: 2017/04/25 14:55:08 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/lemin.h"

static t_room	*make_room(char *line, int type, t_hex *hex)
{
	t_room	*room;
	char	**sline;

	room = (t_room *)malloc(sizeof(t_room));
	sline = ft_strsplit(line, ' ');
	room->type = type;
	room->name = ft_strdup(sline[0]);
	room->x = ft_atoi(sline[1]);
	room->y = ft_atoi(sline[2]);
	room->adjs = init_rooms(hex);
	room->visited = 0;
	room->weight = -1;
	room->used = 0;
	room->ant = 0;
	free_tab(sline);
	return (room);
}

static int		gettype(char **split_map, int map_i)
{
	int type;

	if (ft_strcmp(split_map[map_i - 1], "##start") == 0)
		type = START;
	else if (ft_strcmp(split_map[map_i - 1], "##end") == 0)
		type = END;
	else
		type = NORMAL;
	return (type);
}

t_room			**make_rooms(char **split_map, t_hex *hex)
{
	t_room		**rooms;
	int			map_i;
	int			room_n;
	int			type;

	rooms = allocate_rooms(split_map, hex);
	if (rooms)
	{
		room_n = 0;
		map_i = 1;
		while (split_map[map_i])
		{
			if (split_map[map_i][0] != '#' && ft_strchr(split_map[map_i], ' '))
			{
				type = gettype(split_map, map_i);
				rooms[room_n++] = make_room(split_map[map_i], type, hex);
			}
			map_i += 1;
			rooms[room_n] = NULL;
		}
		return (rooms);
	}
	return (NULL);
}
