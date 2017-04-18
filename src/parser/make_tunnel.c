/* 42 HEADER HERE */

#include "../../incl/lem-in.h"

static	t_room *lookup_room(t_room **rooms, char *name)
{
	int	crawl;

	crawl = 0;
	while (rooms[crawl])
	{
		if (ft_strcmp(rooms[crawl]->name, name) == 0)
			return (rooms[crawl]);
		crawl++;
	}
	return (NULL);
}

static void add_room(t_room **list, t_room *room)
{
	int i;

	i = 0;
	while (list[i] != NULL)
		i++;
	list[i] = room;
}

static void connect(t_room *room1, t_room *room2)
{
	add_room(room1->adjs, room2);
	add_room(room2->adjs, room1);
}

void	make_tunnel(t_hex *hex, char *line)
{
	char **sline;
	t_room *room1;
	t_room *room2;

	sline = ft_strsplit(line, '-');
	room1 = lookup_room(hex->rooms, sline[0]);
	room2 = lookup_room(hex->rooms, sline[1]);
	connect(room1, room2);
}
