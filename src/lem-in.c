/* 42 Header Here */

#include "../incl/lem-in.h"

int	main(void)
{
	char	*map;
	t_hex	*hex;

	map = read_map();
	hex = parse_map(map);
}
