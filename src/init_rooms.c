/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 11:16:32 by mperronc          #+#    #+#             */
/*   Updated: 2017/04/25 11:23:52 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lemin.h"

t_room	**init_rooms(t_hex *hex)
{
	int		i;
	t_room	**list;

	list = (t_room **)malloc(sizeof(t_room *) * hex->n_rooms);
	i = 0;
	while (i < hex->n_rooms)
	{
		list[i] = NULL;
		i++;
	}
	return (list);
}
