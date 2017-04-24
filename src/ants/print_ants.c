/* 42 Header */

#include "../../incl/lem-in.h"

void	print_ants(t_ant **ants)
{
	int		i;

	i = 0;
	while (ants[i])
	{
		ft_printf("Ant %d : %s\n", i+1, ants[i]->pos->name);
		i++;
	}
	ft_printf("\n");
}
