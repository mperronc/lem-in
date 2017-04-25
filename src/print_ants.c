/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 11:16:27 by mperronc          #+#    #+#             */
/*   Updated: 2017/04/25 11:23:52 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lemin.h"

void	print_ants(t_ant **ants)
{
	int		i;

	i = 0;
	while (ants[i])
	{
		ft_printf("Ant %d : %s\n", i + 1, ants[i]->pos->name);
		i++;
	}
	ft_printf("\n");
}
