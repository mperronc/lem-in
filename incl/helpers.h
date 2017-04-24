#ifndef HELPERS_H
#define HELPERS_H

#include "hex.h"

void	print_adj_rooms(t_room *room);
void	print_rooms(t_room **rooms);
void 	print_room(t_room *room);
t_room *lookup_start(t_room **rooms);
t_room *lookup_end(t_room **rooms);
t_room *lookup_room(t_room **rooms, char *name);
t_room **init_rooms(t_hex *hex);
void	print_paths(t_room ***paths);
void	free_tab(char **tab);
int		only_numbers(char *s);

#endif
