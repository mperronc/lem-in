/* 42 Header */

#include "lem-in.h"

static int check_line(char **sline)
{
	// TO DO
	// if len(sline == 3 and sline[1],[2] is only numbers)
	return (1);
}

static t_room *make_room(char *line, int n, int type)
{
	t_room	*room;
	char	**sline;

	room = (t_room *)malloc(sizeof(t_room));
	sline = ft_strsplit(line, ' ');
	if (check_line(sline)) {
		room->id = n;
		room->type = type;
		room->name = ft_strdup(sline[0]);
		room->x = ft_atoi(sline[1]);
		room->y = ft_atoi(sline[2]);
	}
	else {
		ft_putstr("ERROR\n");
		exit(EXIT_FAILURE);
	}
	free(sline);
	return (room);
}

t_room	**make_rooms(char **split_map)
{
	t_room		**rooms;
	int			map_i;
	int			room_n;
	int			type;

	rooms = allocate_rooms(split_map);
	room_n = 0;
	map_i = 1;
	while (split_map[map_i])
	{
		if (split_map[map_i][0] != '#' && ft_strchr(split_map[map_i], ' '))
		{
			if (ft_strcmp(split_map[map_i - 1], "##start") == 0)
				type = 1;
			else if (ft_strcmp(split_map[map_i - 1], "##end") == 0)
				type = 2;
			else
				type = 0;
			rooms[room_n] = make_room(split_map[map_i], room_n, type);
			room_n++;
		}
		map_i += 1;
		rooms[room_n] = NULL;
	}
	return rooms;
}