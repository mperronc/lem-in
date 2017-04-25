/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 11:18:15 by mperronc          #+#    #+#             */
/*   Updated: 2017/04/25 11:33:59 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lemin.h"

int	main(void)
{
	char		**map;
	t_hex		*hex;
	t_room		***paths;
	t_ant		**ants;

	hex = NULL;
	map = read_map();
	if (map)
	{
		map = validate_map(map);
		if (map && map[0])
			hex = parse_map(map);
	}
	if (hex)
	{
		weigh_edges(hex->rooms);
		paths = find_paths(hex);
		if (paths && paths[0])
		{
			hex->n_paths = filter_paths(paths, hex->ants);
			ants = create_ants(hex);
			print_map(map);
			simulate(ants, paths, hex->n_paths);
			free_tab(map);
			exit(EXIT_SUCCESS);
		}
	}
	ft_putstr("ERROR\n");
	exit(EXIT_FAILURE);
}
