/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: russ1337 <russ1337@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:34:24 by rfoo              #+#    #+#             */
/*   Updated: 2026/01/20 06:17:29 by russ1337         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_dict	*dict_init(void)
{
	const char	*keys;
	t_dict	*printf_dict;
	t_entry	*entries;

	keys = "cspdiuxX%";
	printf_dict = malloc(sizeof(t_dict));
	if (!printf_dict)
		return (NULL);
	printf_dict->size = ft_strlen(keys);
	printf_dict->count = 0;
	printf_dict->entries = ft_calloc(ft_strlen(keys), sizeof(t_entry));
	if (!printf_dict->entries)
	{
		free(printf_dict);
		return (NULL);
	}
	add_entries(printf_dict);
	return (printf_dict);
}

static void	dict_set(t_dict *dict, char key, t_handler handler)
{
	int		index;
	t_entry	entry;

	index = 0;
	entry.key = key;
	entry.handler = handler;
	while (index < dict->size)
	{
		if (dict->entries[index].key == key)
		{
			dict->entries[index].handler = handler;
			return ;
		}
		if (!dict->entries[index].key)
		{
			dict->entries[index] = entry;
			return ;
		}
		index++;
	}
}

static void	add_entries(t_dict *dict)
{
	dict_set(dict, 'c', handle_char);
	dict_set(dict, 's', handle_str);
	dict_set(dict, 'p', handle_ptr);
	dict_set(dict, 'd', handle_int);
	dict_set(dict, 'i', handle_int);
	dict_set(dict, 'u', handle_int);
	dict_set(dict, 'x', handle_lowerhex);
	dict_set(dict, 'X', handle_upperhex);
	dict_set(dict, '%', handle_percent);
}

t_handler	dict_get(t_dict *dict, char key)
{
	int	index;

	index = 0;
	while (index < dict->size)
	{
		if (dict->entries[index].key == key)
			return (dict->entries[index].handler);
		index++;
	}
	return (NULL);
}
