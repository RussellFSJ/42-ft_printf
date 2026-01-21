/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 11:58:48 by rfoo              #+#    #+#             */
/*   Updated: 2026/01/21 21:46:17 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	process_s(const char *s, t_dict *dict, va_list *args);
static int	use_handler(char s, t_dict *dict, va_list *args);

int	ft_printf(const char *s, ...)
{
	va_list		args;
	int			bytes;
	t_dict		*dict;

	if (!s)
		return (-1);
	va_start(args, s);
	bytes = 0;
	dict = dict_init();
	bytes = process_s(s, dict, &args);
	va_end(args);
	dict_free(dict);
	return (bytes);
}

static int	process_s(const char *s, t_dict *dict, va_list *args)
{
	int	i;
	int	bytes;

	i = 0;
	bytes = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (!s[i + 1])
				return (bytes + write(1, "%", 1));
			i++;
			bytes += use_handler(s[i], dict, args);
		}
		else
			bytes += write(1, &s[i], 1);
		i++;
	}
	return (bytes);
}

static int	use_handler(char s, t_dict *dict, va_list *args)
{
	t_handler	handler;

	handler = dict_get(dict, s);
	if (handler)
		return (handler(args));
	return (write(1, "%", 1) + write(1, &s, 1));
}
