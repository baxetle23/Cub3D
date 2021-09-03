#include "libft.h"

char	*ft_strdup(const char *s)
{
	return (ft_substr(s, 0, ft_strlen(s)));
}
