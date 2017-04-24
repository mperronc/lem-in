/* 42 Header */

#include "../../incl/lem-in.h"

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

char *read_map(void)
{
	char *line;
	char *map;

	get_next_line(0, &line);
	map = ft_strnew(ft_strlen(line) + 1);
	ft_strcat(map, line);
	ft_strcat(map, "\n");
	free(line);
	while (get_next_line(0, &line))
	{
		map = ft_strjoinfree(map, line);
	}
	ft_printf("%s\n", map);
	free(map);
	return (map);
}
