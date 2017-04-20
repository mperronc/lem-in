#include "../../incl/lem-in.h"

static int	get_max_paths(t_hex *hex)
{
	int		max_paths;
	t_room	*end;

	end = lookup_end(hex->rooms);
	max_paths = 0;
	while (end->adjs[max_paths])
		max_paths++;
	return max_paths;
}

static t_room ***init_paths(int n)
{
	t_room 	***paths;
	int		i;

	paths = (t_room ***)malloc(sizeof(t_room **) * n + 1);
	i = 0;
	while (i <= n)
	{
		paths[i] = NULL;
		i++;
	}
	return paths;
}

t_room ***find_paths(t_hex *hex)
{
	int		max_paths;
	t_room	***paths;
	int		i;

	max_paths = get_max_paths(hex);
	paths = init_paths(max_paths);
	i = 0;
	while (i < max_paths)
	{
		paths[i] = find_path(lookup_start(hex->rooms), hex);
		i++;
	}
	return (paths);
}
