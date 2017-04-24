/* Quarante-deux */

#include "../../incl/lem-in.h"

t_ant	**create_ants(t_hex *hex) {
	t_ant	**ants;
	int		i;

	ants = (t_ant **)malloc(sizeof(t_ant *) * (hex->ants + 1));
	i = 0;
	while (i < hex->ants)
	{
		ants[i] = (t_ant *)malloc(sizeof(t_ant *));
		ants[i]->pos = lookup_start(hex->rooms);
		ants[i]->ppos = NULL;
		i++;
	}
	ants[i] = NULL;
	return (ants);
}
