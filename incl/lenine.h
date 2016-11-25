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

/*	Graph implementation using an adjacency linked list */

typedef struct		s_node
{
	int				dest;
	struct s_node	*next;
}					t_node;

typedef struct		s_adj_list
{
	t_node			*head;
}					t_adj_list;

typedef struct		s_graph
{
	int				n_nodes;
	t_adj_list		*adj_list;
}					t_graph;

t_node				*new_node(int dest);
t_graph				*new_graph(int n_nodes);
void				add_edge(t_graph *graph, int src, int dest);
void				print_graph(t_graph *graph);

#endif
