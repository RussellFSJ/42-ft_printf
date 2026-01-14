/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 19:52:43 by rfoo              #+#    #+#             */
/*   Updated: 2026/01/14 18:27:04 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
typedef struct entry
{
	char	key;
	void	(*handler)(void*);
}			t_entry;

typedef struct dict
{
	int		size;
	int		count;
	t_entry	*entries;
}			t_dict;

int		ft_printf(const char *format, ...);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putlowerhex_fd(unsigned int n, int fd);
void	ft_putupperhex_fd(unsigned int n, int fd);
void	ft_putptr_fd(unsigned int n, int fd);
void	handle_char(char c);
void	handle_str(char *s);
void	handle_int(int n);
void	handle_ptr(void *ptr);
void	handle_lowerhex(unsigned int n);
void	handle_upperhex(unsigned int n);
void	handle_percent(void);

#endif