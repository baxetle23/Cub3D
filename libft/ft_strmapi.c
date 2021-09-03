#include "libft.h"

static char	*ft_strnew(size_t size);
static void	*ft_memalloc(size_t size);

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*res;

	i = 0;
	if (!s || !f)
		return (NULL);
	res = ft_strnew(ft_strlen(s));
	if (res != NULL)
	{
		while (s[i] != '\0')
		{
			res[i] = f(i, s[i]);
			i++;
		}
	}
	else
		return (NULL);
	return (res);
}

char	*ft_strnew(size_t size)
{
	return ((char *)ft_memalloc(size + 1));
}

void	*ft_memalloc(size_t size)
{
	void	*pointer;

	pointer = malloc(size);
	if (pointer == NULL)
		return (pointer);
	ft_bzero(pointer, size);
	return (pointer);
}
