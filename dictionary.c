/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:34:24 by rfoo              #+#    #+#             */
/*   Updated: 2026/01/14 18:12:29 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_dict	*dict_init(int dict_size)
{
	t_dict	*printf_dict;
	t_entry	*entries;

	printf_dict = malloc(sizeof(t_dict));
	if (!printf_dict)
		return (NULL);
	printf_dict->size = dict_size;
	printf_dict->count = 0;
	printf_dict->entries = ft_calloc(dict_size, sizeof(t_entry));
	if (!entries)
	{
		free(printf_dict);
		return (NULL);
	}
	add_entries(printf_dict);
	return (printf_dict);
}

static int	dict_size(char *keys)
{
	return ft_strlen(keys);
}

static void dict_set(t_dict *dict, char key, void (*handler)(void*))
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
static void add_entries(t_dict *dict)
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
void	(*dict_get(t_dict *dict, char key))(void *)
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
