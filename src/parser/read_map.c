/* 42 Header */

#include "../../incl/lem-in.h"
#include <string.h>

char *read_map(void)
{
	char *line;
	char *map;

	map = ft_strnew(64000);
	while (get_next_line(0, &line))
	{
		strcat(map, line);
		strcat(map, "\n");
		free(line);
	}
	free(map);
	return (map);
}
