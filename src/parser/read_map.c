/* 42 Header */

#include "../../incl/lem-in.h"

char *read_map(void)
{
	char *line;
	char *map;

	// SHITS INSCECURE YO
	map = ft_strnew(64000);
	while (get_next_line(0, &line))
	{
		ft_strcat(map, line);
		ft_strcat(map, "\n");
		free(line);
	}
	free(map);
	return (map);
}
