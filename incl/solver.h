/* 42 HEADER HERE */

#ifndef SOLVER_H
#define SOLVER_H

#include "hex.h"

t_room	*select_next(t_room *cur);
void	weigh_edges(t_room **rooms);
void	weigh_neighbors(t_room *cur);

#endif
