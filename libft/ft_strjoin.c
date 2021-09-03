#include "libft.h"

static char	*ft_strnew(size_t size);
static void	*ft_memalloc(size_t size);

char	*ft_strjoin(const char *s1, const char *s2)
{
	char		*new_string;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	new_string = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (new_string == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		new_string[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		new_string[i] = s2[j];
		i++;
		j++;
	}
	return (new_string);
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
