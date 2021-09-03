#include "libft.h"

char	*ft_strchr(const char *src, int c)
{
	size_t	i;
	char	*s;

	s = (char *)src;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	if (s[i] == '\0' && s[i] == c)
		return (&s[i]);
	return (NULL);
}
