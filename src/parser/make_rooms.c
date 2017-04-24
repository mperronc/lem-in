/* 42 Header */

#include "../../incl/lem-in.h"

static t_room *make_room(char *line, int n, int type, t_hex *hex)
{
	t_room	*room;
	char	**sline;

	room = (t_room *)malloc(sizeof(t_room));
	sline = ft_strsplit(line, ' ');
	room->id = n;
	room->type = type;
	room->name = ft_strdup(sline[0]);
	room->x = ft_atoi(sline[1]);
	room->y = ft_atoi(sline[2]);
	room->adjs = init_rooms(hex);
	room->visited = 0;
	room->weight = -1;
	room->used = 0;
	room->ant = 0;
	free(sline);
	return (room);
}

t_room	**make_rooms(char **split_map, t_hex *hex)
{
	t_room		**rooms;
	int			map_i;
	int			room_n;
	int			type;

	rooms = allocate_rooms(split_map, hex);
	if (rooms) {
		room_n = 0;
		map_i = 1;
		while (split_map[map_i])
		{
			if (split_map[map_i][0] != '#' && ft_strchr(split_map[map_i], ' '))
			{
				if (ft_strcmp(split_map[map_i - 1], "##start") == 0)
					type = START;
				else if (ft_strcmp(split_map[map_i - 1], "##end") == 0)
					type = END;
				else
					type = NORMAL;
				rooms[room_n] = make_room(split_map[map_i], room_n, type, hex);
				room_n++;
			}
			map_i += 1;
			rooms[room_n] = NULL;
		}
		return rooms;
	}
	return (NULL);
}
