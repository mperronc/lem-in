/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tunnels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 11:17:21 by mperronc          #+#    #+#             */
/*   Updated: 2017/04/25 11:27:12 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lemin.h"

void	make_tunnels(t_hex *hex, char **split_map)
{
	int	map_i;

	map_i = 0;
	while (split_map[map_i])
	{
		if (ft_strchr(split_map[map_i], '#') == 0
			&& ft_strchr(split_map[map_i], '-') != 0)
			make_tunnel(hex, split_map[map_i]);
		map_i++;
	}
}
