/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_entry.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:36:21 by mperronc          #+#    #+#             */
/*   Updated: 2016/11/25 16:46:54 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/dict.h"
#include "../incl/lenine.h"

t_dict	*append_entry(t_dict **dict, char *key, int value)
{
	t_dict			*tmp;
	unsigned int	hashval;

	if ((tmp = get_value(dict, key)) == NULL)
	{
		tmp = (t_dict *)malloc(sizeof(t_dict));
		if (tmp == NULL || (tmp->key = ft_strdup(key)) == NULL)
			return (NULL);
		tmp->value = value;
		hashval = hash_string(key);
		tmp->next = dict[hashval];
		dict[hashval] = tmp;
	}
	return (tmp);
}
