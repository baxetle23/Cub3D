#include "libft.h"

void	ft_bzero(void *s, size_t size)
{
	while (size)
	{
		*((char *)s) = 0;
		size--;
		s++;
	}
}
