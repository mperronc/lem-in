/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 11:18:35 by mperronc          #+#    #+#             */
/*   Updated: 2017/04/25 11:36:27 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEX_H
# define HEX_H

# define NORMAL 0
# define START 1
# define END 2

typedef struct		s_room {
	int				id;
	char			*name;
	int				x;
	int				y;
	int				type;
	int				weight;
	int				visited;
	int				used;
	int				ant;
	struct s_room	**adjs;
}					t_room;

typedef struct		s_hex {
	int				ants;
	int				n_paths;
	int				n_rooms;
	t_room			**rooms;
}					t_hex;

#endif
