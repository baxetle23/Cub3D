#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	if (s[i] == c)
		return ((char *) s + i);
	while (i-- != 0)
	{
		if (s[i] == c)
			return ((char *) s + i);
	}
	return (NULL);
}
