/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 11:17:42 by mperronc          #+#    #+#             */
/*   Updated: 2017/04/25 11:31:19 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/lemin.h"

static int	path_len(t_room **path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		i++;
	}
	return (i);
}

int			filter_paths(t_room ***paths, int n_ants)
{
	int		n_paths;

	n_ants -= path_len(paths[0]);
	n_paths = 1;
	while (paths[n_paths] && n_ants > path_len(paths[n_paths]))
	{
		n_ants -= path_len(paths[n_paths]);
		n_paths++;
	}
	return (n_paths);
}
