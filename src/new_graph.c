/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_graph.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:36:21 by mperronc          #+#    #+#             */
/*   Updated: 2016/11/25 16:46:54 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lenine.h"

t_graph		*new_graph(int n_nodes)
{
	t_graph		*graph;
	int			i;

	graph = (t_graph *)malloc(sizeof(t_graph));
	graph->n_nodes = n_nodes;
	graph->adj_list = (t_adj_list *)malloc(sizeof(t_adj_list) * n_nodes);
	i = 0;
	while (i < n_nodes)
	{
		graph->adj_list[i].head = NULL;
		i++;
	}
	return (graph);
}
