/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: russ1337 <russ1337@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:03:39 by rfoo              #+#    #+#             */
/*   Updated: 2026/01/16 06:43:38 by russ1337         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_int(int n)
{
	long	nbr;
	int		count;

	nbr = n;
	count = 0;
	if (nbr < 0)
	{
		count += handle_char('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
		count += handle_int(nbr / 10);
	count += handle_char((nbr % 10) + '0');
	return count;
}
