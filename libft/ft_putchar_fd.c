#include "libft.h"

void	ft_putchar_fd(int c, int fd)
{
	write(fd, &c, 1);
}
