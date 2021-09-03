#include "libft.h"

static void	print_nbr_fd(unsigned int n, int fd)
{
	char	digit;

	if (n > 9)
		print_nbr_fd(n / 10, fd);
	digit = n % 10 + '0';
	ft_putchar_fd(digit, fd);
}

void	ft_putnbr_fd(long long n, int fd)
{
	size_t			minus;
	long long		value;

	minus = n < 0;
	if (minus)
	{
		ft_putchar_fd('-', fd);
		value = -n;
	}
	else
		value = n;
	print_nbr_fd(value, fd);
}
