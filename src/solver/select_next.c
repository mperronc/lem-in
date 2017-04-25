/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_next.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 11:17:57 by mperronc          #+#    #+#             */
/*   Updated: 2017/04/25 11:31:29 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/lemin.h"

t_room	*select_next(t_room **rooms)
{
	int		i;
	t_room	*next;

	i = 0;
	next = NULL;
	while (rooms[i])
	{
		if (!next && rooms[i]->weight != -1 && !rooms[i]->visited)
			next = rooms[i];
		else if (next && rooms[i]->weight != -1
				&& next->weight > rooms[i]->weight && !rooms[i]->visited)
			next = rooms[i];
		i++;
	}
	return (next);
}
