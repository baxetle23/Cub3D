#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	s_len;
	size_t	d_len;
	size_t	remaining_size;
	size_t	copy_len;

	s_len = ft_strlen(src);
	remaining_size = n;
	while (*dest && remaining_size > 0)
	{
		dest++;
		remaining_size--;
	}
	d_len = n - remaining_size;
	if (d_len < n)
	{
		copy_len = remaining_size - 1;
		if (s_len < copy_len)
			copy_len = s_len;
		ft_memcpy(dest, src, copy_len);
		dest[copy_len] = '\0';
	}
	return (d_len + s_len);
}
