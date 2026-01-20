/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: russ1337 <russ1337@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 19:52:43 by rfoo              #+#    #+#             */
/*   Updated: 2026/01/19 18:02:28 by russ1337         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef int	(*t_handler)(void*);
typedef struct entry
{
	char		key;
	t_handler	handler;
}			t_entry;

typedef struct dict
{
	int		size;
	int		count;
	t_entry	*entries;
}			t_dict;

size_t		ft_strlen(const char *s);
void		*ft_memset(void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
int			print_hex(unsigned long n, int uppercase);
int			handle_char(va_list *args);
int			handle_str(va_list *args);
int			handle_int(va_list *args);
int			handle_ptr(va_list *args);
int			handle_lowerhex(va_list *args);
int			handle_upperhex(va_list *args);
int			handle_percent(void);
t_dict		*dict_init(void);
t_handler	dict_get(t_dict *dict, char key);
int			ft_printf(const char *s, ...);

#endif
