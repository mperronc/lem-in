/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:36:21 by mperronc          #+#    #+#             */
/*   Updated: 2016/11/25 16:46:54 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lenine.h"

void	print_graph(t_graph *graph)
{
	int		i;
	t_node	*tmp;

	i = 0;
	while (i < graph->n_nodes)
	{
		tmp = graph->adj_list[i].head;
		printf("\n Adjacency list of vertex %d\n head ", i);
		while (tmp)
		{
			printf("-> %d ", tmp->dest);
			tmp = tmp->next;
		}
		printf("\n");
		i++;
	}
}
