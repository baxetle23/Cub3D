#include "libft.h"

static void	*ft_memalloc(size_t size);

void	*ft_calloc(size_t count, size_t size)
{
	return (ft_memalloc(count * size));
}

void	*ft_memalloc(size_t size)
{
	void	*pointer;

	pointer = malloc(size);
	if (pointer == NULL)
	{
		return (pointer);
	}
	ft_bzero(pointer, size);
	return (pointer);
}
