/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: russ1337 <russ1337@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 11:58:48 by rfoo              #+#    #+#             */
/*   Updated: 2026/01/20 08:54:50 by russ1337         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list		args;
	int			i;
	int			bytes;
	t_dict		*dict;

	va_start(args, s);
	i = 0;
	bytes = 0;
	dict = dict_init();
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (!s[i + 1]) 
				return (bytes + write(1, "%", 1));
			i++;
			bytes += use_handler(s[i], dict, &args);
		}
		else 
			bytes += write(1, &s[i], 1);
		i++;
	}
	va_end(args);
	return (bytes);
}

int	use_handler(char s, t_dict *dict, va_list *args)
{
	t_handler	handler;

	handler = dict_get(dict, s);
	if (handler)
		return (handler(args));
	return (write(1, "%", 1) + write(1,&s, 1));
}