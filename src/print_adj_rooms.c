/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_adj_rooms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 11:16:49 by mperronc          #+#    #+#             */
/*   Updated: 2017/04/25 11:23:52 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lemin.h"

void	print_adj_rooms(t_room *room)
{
	int	i;

	i = 0;
	while (room->adjs[i])
	{
		ft_printf("%s ", room->adjs[i]->name);
		i++;
	}
	ft_printf("\n\n");
}
