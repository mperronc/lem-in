/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 11:16:20 by mperronc          #+#    #+#             */
/*   Updated: 2017/05/01 17:16:04 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lemin.h"

static void	reset_ants_moved_flag(t_ant **ants)
{
	int	i;

	i = 0;
	while (ants[i])
	{
		ants[i]->moved = 0;
		i++;
	}
}

static int	get_pos(t_room *pos, t_room **path)
{
	int		i;

	i = 0;
	while (path[i])
	{
		if (path[i] == pos)
			return (i);
		i++;
	}
	return (-1);
}

static int	move_ant(t_ant *ant, t_room **path)
{
	int		ipos;

	if (ant->pos->type == END)
		return (0);
	ipos = get_pos(ant->pos, path);
	if (ipos >= 0 && (ipos == 1 || path[ipos - 1]->ant == 0) && !ant->moved)
	{
		ant->pos = path[ipos - 1];
		path[ipos - 1]->ant = 1;
		path[ipos]->ant = 0;
		ant->moved = 1;
		return (1);
	}
	return (0);
}

static int	move_ants(t_ant **ants, t_room ***paths, int n_paths)
{
	int		i;
	int		j;
	int		moves;

	i = 0;
	moves = 0;
	while (ants[i])
	{
		j = 0;
		while (j < n_paths)
		{
			if (move_ant(ants[i], paths[j]))
			{
				ft_printf("L%d-%s ", i + 1, ants[i]->pos->name);
				moves++;
			}
			j++;
		}
		i++;
	}
	return (moves);
}

void		simulate(t_ant **ants, t_room ***paths, int n_paths)
{
	while (move_ants(ants, paths, n_paths))
	{
		reset_ants_moved_flag(ants);
		ft_printf("\n");
	}
}
