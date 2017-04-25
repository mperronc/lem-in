/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weigh_neighbors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 11:18:10 by mperronc          #+#    #+#             */
/*   Updated: 2017/04/25 11:23:53 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/lemin.h"

void	weigh_neighbors(t_room *cur)
{
	int		i;

	i = 0;
	while (cur->adjs[i])
	{
		if (cur->adjs[i]->weight == -1 || cur->adjs[i]->weight > cur->weight)
			cur->adjs[i]->weight = cur->weight + 1;
		i++;
	}
}
