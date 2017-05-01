/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_one_start_end.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 17:25:12 by mperronc          #+#    #+#             */
/*   Updated: 2017/05/01 17:30:23 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lemin.h"

int	only_one_start_end(char **map)
{
	int n_start;
	int n_end;
	int	i;

	n_start = 0;
	n_end = 0;
	i = 0;
	while (map[i])
	{
		if (ft_strcmp(map[i], "##start") == 0)
			n_start++;
		if (ft_strcmp(map[i], "##end") == 0)
			n_end++;
		i++;
	}
	return (n_start == 1 && n_end == 1);
}
