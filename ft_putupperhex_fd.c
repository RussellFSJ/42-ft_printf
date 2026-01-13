#include "ft_printf.h"

void	ft_putupperhex_fd(unsigned int n, int fd)
{
	char	*hex;
	char	buffer[9];
	int		i;

	hex = "0123456789ABCDEF";
	i = 8;
	buffer[i] = '\0';
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return;
	}
	while (n > 0)
	{
		buffer[--i] = hex[n % 16];
		n /= 16;
	}
	ft_putstr_fd(&buffer[i], fd);
}