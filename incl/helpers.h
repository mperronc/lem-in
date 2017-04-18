#ifndef HELPERS_H
#define HELPERS_H

#include "hex.h"

void	print_adj_rooms(t_room *room);
void	print_rooms(t_room **rooms);
t_room *lookup_start(t_room **rooms);
t_room *lookup_end(t_room **rooms);
t_room *lookup_room(t_room **rooms, char *name);

#endif
