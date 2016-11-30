/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lenine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:36:21 by mperronc          #+#    #+#             */
/*   Updated: 2016/11/25 16:46:54 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LENINE_H
# define LENINE_H

#include <stdio.h>
#include <stdlib.h>

#include "../libft/incl/libft.h"
#include "../libft/incl/ft_printf.h"

/*	A room needs to know if is already chosen when finding multiple paths	*/
typedef struct		s_room
{
	char			*name;
	int				clogged;
}					t_room;

/*	Adjacency link */
typedef struct		s_link
{
	int				dest;
	struct s_link	*next;
}					t_link;

/*	Adjacency list */
typedef struct		s_adj_list
{
	t_link			*head;
}					t_adj_list;

/* Whole graph */
typedef struct		s_graph
{
	int				n_nodes;
	t_adj_list		*adj_list;
}					t_graph;

/* 	Project wide struct containing array of rooms, number of ants and indexes
	of the starting and ending rooms										  */
typedef struct		s_lemin
{
	t_room			*rooms;
	t_graph			*graph;
	int				n_ants;
	int				start_index;
	int				end_index;
}					t_lemin;

t_link				*new_link(int dest);
t_graph				*new_graph(int n_nodes);
void				add_edge(t_graph *graph, int src, int dest);
void				print_graph(t_graph *graph);

#endif
