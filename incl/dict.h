/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:36:21 by mperronc          #+#    #+#             */
/*   Updated: 2016/11/25 16:46:54 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
# define DICT_H

#define HASHSIZE 1009

typedef struct		s_dict
{
	struct s_dict	*next;
	char			*key;
	int				value;
}					t_dict;

unsigned int		hash_string(char *s);
t_dict				*get_value(t_dict **dict, char *key);
t_dict				*append_entry(t_dict **dict, char *key, int value);

#endif
