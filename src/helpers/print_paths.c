#include "../../incl/lem-in.h"

void	print_paths(t_room ***paths)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		ft_printf("====== PATH %d ======\n\n", i + 1);
		print_rooms(paths[i]);
		i++;
	}
}
