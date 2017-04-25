/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 11:18:43 by mperronc          #+#    #+#             */
/*   Updated: 2017/04/25 11:37:01 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "hex.h"

char	**read_map(void);
t_hex	*parse_map(char **split_map);
t_room	**make_rooms(char **split_map, t_hex *hex);
t_room	**allocate_rooms(char **split_map, t_hex *hex);
void	make_tunnels(t_hex *hex, char **split_map);
void	make_tunnel(t_hex *hex, char *line);
char	**validate_map(char **map);

#endif
