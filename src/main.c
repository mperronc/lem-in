/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:36:21 by mperronc          #+#    #+#             */
/*   Updated: 2016/11/25 16:46:54 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lenine.h"
#include "../incl/dict.h"

int		main(void)
{
	t_dict		**table;
	t_dict		*elem;

	table = (t_dict **)malloc(sizeof(t_dict *) * HASHSIZE);
	append_entry(table, "toto", 1);
	elem = get_value(table, "toto");
	ft_printf("%d\n", elem->value);
}
