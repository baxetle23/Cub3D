#include "libft.h"

void	fun(char *a, const char *b, size_t *i);

void	*ft_memmove(void *to, const void *src, size_t n)
{
	char		*dest;
	const char	*source;
	size_t		i;

	if (!to && !src && n)
		return (NULL);
	dest = (char *)to;
	source = (const char *)src;
	i = 0;
	if (dest <= source)
	{
		while (i < n)
			fun(&dest[i], &source[i], &i);
	}
	else
	{
		i = n;
		while (i > 0)
		{
			dest[i - 1] = source[i - 1];
			i--;
		}
	}
	return (dest);
}

void	fun(char *a, const char *b, size_t *i)
{
	*a = *b;
	*i += 1;
}
