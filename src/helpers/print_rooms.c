/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 11:16:58 by mperronc          #+#    #+#             */
/*   Updated: 2017/04/25 11:23:52 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/lemin.h"

void	print_room(t_room *room)
{
	ft_printf("Name : %s Weight : %d\n", room->name, room->weight);
	ft_printf("Connected to :\n");
	print_adj_rooms(room);
}

void	print_rooms(t_room **rooms)
{
	int i;

	i = 0;
	while (rooms[i] != NULL)
	{
		print_room(rooms[i]);
		i++;
	}
}
