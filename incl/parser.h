/*42 Header */

#ifndef PARSER_H
# define PARSER_H

#include "hex.h"

char	*read_map(void);
t_hex   *parse_map(char *map);
int		get_ants(char *nants);
t_room  **make_rooms(char **split_map);
t_room	**allocate_rooms(char **split_map);

#endif
