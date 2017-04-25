/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 11:17:52 by mperronc          #+#    #+#             */
/*   Updated: 2017/04/25 12:59:52 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lemin.h"

static int		get_max_paths(t_hex *hex)
{
	int		max_paths;
	t_room	*end;

	end = lookup_end(hex->rooms);
	max_paths = 0;
	while (end->adjs[max_paths])
		max_paths++;
	return (max_paths);
}

static t_room	***init_paths(int n)
{
	t_room	***paths;
	int		i;

	paths = (t_room ***)malloc(sizeof(t_room **) * (n + 1));
	i = 0;
	while (i <= n)
	{
		paths[i] = NULL;
		i++;
	}
	return (paths);
}

t_room			***find_paths(t_hex *hex)
{
	int		max_paths;
	t_room	***paths;
	int		i;

	max_paths = get_max_paths(hex);
	paths = init_paths(max_paths);
	i = 0;
	while (i < max_paths)
	{
		while (!paths[i])
			paths[i] = find_path(lookup_end(hex->rooms), hex);
		i++;
	}
	return (paths);
}
