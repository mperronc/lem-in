/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weigh_edges.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 11:18:02 by mperronc          #+#    #+#             */
/*   Updated: 2017/04/25 11:23:53 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/lemin.h"

void	weigh_edges(t_room **rooms)
{
	t_room *cur;

	cur = lookup_start(rooms);
	cur->weight = 0;
	while (cur != NULL)
	{
		weigh_neighbors(cur);
		cur->visited = 1;
		cur = select_next(rooms);
	}
}
