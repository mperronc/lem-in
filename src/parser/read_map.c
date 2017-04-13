/* 42 Header */

#include "lem-in.h"

char *read_map(void)
{
	char *line;
	char *map;

	map = (char *) malloc(sizeof(char));
	while (get_next_line(0, &line))
	{
		map = ft_strjoin(map, line);
		map = ft_strjoin(map, "\n");
	}
	return (map);
}
