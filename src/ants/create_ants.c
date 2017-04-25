/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 11:16:08 by mperronc          #+#    #+#             */
/*   Updated: 2017/04/25 12:32:44 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/lemin.h"

t_ant	**create_ants(t_hex *hex)
{
	t_ant	**ants;
	int		i;

	ants = (t_ant **)malloc(sizeof(t_ant *) * (hex->ants + 1));
	i = 0;
	while (i < hex->ants)
	{
		ants[i] = (t_ant *)malloc(sizeof(t_ant));
		ants[i]->pos = lookup_start(hex->rooms);
		i++;
	}
	ants[i] = NULL;
	return (ants);
}
