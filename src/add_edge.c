/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_edge.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:36:21 by mperronc          #+#    #+#             */
/*   Updated: 2016/11/25 16:46:54 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lenine.h"

void	add_edge(t_graph *graph, int src, int dest)
{
	t_node	*node;

	node = new_node(dest);
	node->next = graph->adj_list[src].head;
	graph->adj_list[src].head = node;
	node = new_node(src);
	node->next = graph->adj_list[dest].head;
	graph->adj_list[dest].head = node;
}
