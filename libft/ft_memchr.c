#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*tmp;

	tmp = (char *)s;
	while (n > 0)
	{
		if (*tmp == c)
			return (tmp);
		tmp++;
		n--;
	}
	return (NULL);
}
