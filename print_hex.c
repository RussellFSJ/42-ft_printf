#include "ft_printf.h"

int	print_hex(unsigned long n, int uppercase)
{
	const char	*hex;
	char		buffer[17];
	int			i;

	hex = "0123456789abcdef";
	if (uppercase)
		hex = "0123456789ABCDEF";
	i = 16;
	buffer[i] = '\0';
	if (n == 0)
		return (write(1, "0", 1));
	while (n > 0)
	{
		buffer[--i] = hex[n % 16];
		n /= 16;
	}
	return (write(1, &buffer[i], 16 - i));
}