/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 11:18:15 by mperronc          #+#    #+#             */
/*   Updated: 2017/05/01 17:28:43 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lemin.h"

static void	solve(t_hex *hex, t_ant ***ants, char **map, t_room ***paths)
{
	hex->n_paths = filter_paths(paths, hex->ants);
	*ants = create_ants(hex);
	print_map(map);
	simulate(*ants, paths, hex->n_paths);
}

int			main(void)
{
	char		**map;
	t_hex		*hex;
	t_room		***paths;
	t_ant		**ants;

	map = NULL;
	hex = NULL;
	paths = NULL;
	ants = NULL;
	map = read_map();
	if (map)
	{
		map = validate_map(map);
		if (map && map[0] && only_one_start_end(map))
			hex = parse_map(map);
	}
	if (hex)
	{
		weigh_edges(hex->rooms);
		paths = find_paths(hex);
		if (paths && paths[0])
			solve(hex, &ants, map, paths);
	}
	free_lemin(map, hex, paths, ants);
}
