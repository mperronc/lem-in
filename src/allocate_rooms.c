/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_rooms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 11:17:05 by mperronc          #+#    #+#             */
/*   Updated: 2017/04/25 12:55:26 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lemin.h"

t_room		**allocate_rooms(char **split_map, t_hex *hex)
{
	int		n_rooms;
	int		map_i;
	t_room	**rooms;

	n_rooms = 0;
	map_i = 1;
	while (split_map[map_i])
	{
		if (split_map[map_i][0] != '#' && ft_strchr(split_map[map_i], ' '))
			n_rooms += 1;
		map_i += 1;
	}
	if (n_rooms >= 2)
	{
		rooms = (t_room **)malloc(sizeof(t_room *) * (n_rooms + 1));
		hex->n_rooms = n_rooms;
		return (rooms);
	}
	else
		return (NULL);
}
