#ifndef ANTS_H
# define ANTS_H

#include	"hex.h"

typedef struct s_ant {
	t_room	*pos;
	t_room	*ppos;
}				t_ant;

t_ant	**create_ants(t_hex *hex);
void	print_ants(t_ant **ants);
void	simulate(t_ant **ants, t_room ***paths, int n_paths);


#endif
