#include "libft.h"

static char	*ft_strnew(size_t size);
static void	*ft_memalloc(size_t size);

char	*ft_itoa(int n)
{
	char			*string;
	char			tmp[12];
	char			*tmp_pointer;
	size_t			i;
	unsigned int	value;

	i = 0;
	tmp_pointer = tmp;
	if (n < 0)
		value = n * -1;
	else
		value = n;
	while (value || tmp == tmp_pointer)
	{
		*tmp_pointer++ = value % 10 + '0';
		value /= 10;
	}
	if (n < 0)
		*tmp_pointer++ = '-';
	string = ft_strnew((size_t)(tmp_pointer - tmp));
	if (!(string))
		return (NULL);
	while (tmp_pointer != tmp)
		string[i++] = *--tmp_pointer;
	return (string);
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
