/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:36:21 by mperronc          #+#    #+#             */
/*   Updated: 2016/11/25 16:46:54 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/dict.h"
#include "../incl/lenine.h"

unsigned int	hash_string(char *s)
{
	unsigned int hashval;

	hashval = 0;
	while (*s)
	{
		hashval = *s + 31 * hashval;
		s++;
	}
	return (hashval % HASHSIZE);
}
