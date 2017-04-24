/* 42 HEADER HERE */

#ifndef SOLVER_H
#define SOLVER_H

#include "hex.h"

#define FREE 0
#define USED 1

t_room	*select_next(t_room **rooms);
void	weigh_edges(t_room **rooms);
void	weigh_neighbors(t_room *cur);
t_room	**find_path(t_room *start, t_hex *hex);
t_room ***find_paths(t_hex *hex);
int	filter_paths(t_room ***paths, int n_ants);

#endif
