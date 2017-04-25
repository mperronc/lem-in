/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 11:16:54 by mperronc          #+#    #+#             */
/*   Updated: 2017/04/25 11:23:52 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lemin.h"

void	print_paths(t_room ***paths)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		ft_printf("====== PATH %d ======\n\n", i + 1);
		print_rooms(paths[i]);
		i++;
	}
}
