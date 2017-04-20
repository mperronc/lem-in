#include "../../incl/lem-in.h"

t_room **init_rooms(t_hex *hex)
{
	int i;
	t_room **list;

	list = (t_room **)malloc(sizeof(t_room *) * hex->n_rooms);
	i = 0;
	while (i < hex->n_rooms)
	{
		list[i] = NULL;
		i++;
	}
	return (list);
}
