/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 11:17:36 by mperronc          #+#    #+#             */
/*   Updated: 2017/04/25 12:56:08 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lemin.h"

static int	map_len(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

static int	room_format(char *line)
{
	char	**sp;
	int		ok;

	ok = 0;
	sp = ft_strsplit(line, ' ');
	if (sp[2] && !sp[3])
	{
		if (sp[0][0] != 'L' && !ft_strchr(sp[0], '-')
			&& only_numbers(sp[1]) && only_numbers(sp[2]))
			ok = 1;
	}
	free_tab(sp);
	return (ok);
}

static int	link_format(char *line)
{
	char	**sp;
	int		ok;

	ok = 0;
	sp = ft_strsplit(line, '-');
	if (sp[1] && !sp[2])
		ok = 1;
	free_tab(sp);
	return (ok);
}

static int	line_is_valid(char *line, int *stage)
{
	if (line[0] == '#')
		return (1);
	if (*stage == 0)
	{
		*stage = 1;
		return (only_numbers(line));
	}
	else if (*stage == 1)
	{
		if (!room_format(line))
			*stage = 2;
		else
			return (1);
	}
	if (*stage == 2)
	{
		return (link_format(line));
	}
	return (0);
}

char		**validate_map(char **map)
{
	char	**val_map;
	int		i;
	int		stage;

	i = 0;
	stage = 0;
	val_map = (char **)malloc(sizeof(char *) * (map_len(map) + 1));
	while (map[i] && line_is_valid(map[i], &stage))
	{
		val_map[i] = ft_strdup(map[i]);
		i++;
	}
	val_map[i] = NULL;
	free_tab(map);
	return (val_map);
}
