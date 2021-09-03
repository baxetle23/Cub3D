#include "libft.h"

static size_t	ft_strnlen(char *str, size_t max_size);

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	lit_len;
	char	proverka;

	i = 0;
	if (ft_strlen(big) < ft_strlen(little))
		return (0);
	if (!big)
		proverka = *big;
	lit_len = ft_strnlen((char *)little, len);
	if ((0 == lit_len && len != 0) || little[0] == 0)
		return ((char *)big);
	while (i <= len - lit_len)
	{
		if (big[0] == little[0] && 0 == ft_strncmp(big, little, lit_len))
			return ((char *)big);
		big++;
		i++;
	}
	return (NULL);
}

size_t	ft_strnlen(char *str, size_t max_size)
{
	if (ft_strlen(str) > max_size)
		return (max_size);
	else
		return (ft_strlen(str));
}
