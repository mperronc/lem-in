/* 42 Header Here */

#include "../incl/lem-in.h"

int	main(void)
{
	char	*map;
	t_room	**hex;

	map = read_map();
	hex = parse_map(map);
}
