/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 11:17:32 by mperronc          #+#    #+#             */
/*   Updated: 2017/04/25 11:28:44 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/lemin.h"

char	*ft_strjoinfree(char *s1, char *s2)
{
	char	*new;

	new = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	ft_strcat(new, s1);
	ft_strcat(new, s2);
	ft_strcat(new, "\n");
	free(s1);
	free(s2);
	return (new);
}

char	**read_map(void)
{
	char *line;
	char *map;
	char **smap;

	line = NULL;
	get_next_line(0, &line);
	if (line)
	{
		map = ft_strnew(ft_strlen(line) + 1);
		ft_strcat(map, line);
		ft_strcat(map, "\n");
		free(line);
		while (get_next_line(0, &line))
		{
			map = ft_strjoinfree(map, line);
		}
		smap = ft_strsplit(map, '\n');
		free(map);
		return (smap);
	}
	return (NULL);
}
