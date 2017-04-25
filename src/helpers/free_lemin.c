/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lemin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 11:47:12 by mperronc          #+#    #+#             */
/*   Updated: 2017/04/25 13:00:00 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/lemin.h"

static void	free_rooms(t_room **rooms)
{
	int i;

	i = 0;
	while (rooms[i])
	{
		free(rooms[i]->name);
		free(rooms[i]->adjs);
		i++;
	}
	free(rooms);
}

static void free_hex(t_hex *hex)
{
	if (hex->rooms)
		free_rooms(hex->rooms);
	free(hex);
}

static void free_paths(t_room ***paths)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}

static void	free_ants(t_ant **ants)
{
	int i;

	i = 0;
	while (ants[i])
	{
		free(ants[i]);
		i++;
	}
	free(ants);
}

void		free_lemin(char **map, t_hex *hex, t_room ***paths, t_ant **ants)
{
	int yes;

	yes = 0;
	if (map && hex && paths && ants)
		yes = 1;
	if (map)
		free_tab(map);
	if (hex)
		free_hex(hex);
	if (paths)
		free_paths(paths);
	if (ants)
		free_ants(ants);
	if (yes)
		exit(EXIT_SUCCESS);
	else
	{
		ft_putstr("ERROR\n");
		exit(EXIT_FAILURE);
	}
}
