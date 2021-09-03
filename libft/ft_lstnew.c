#include "libft.h"

t_list	*ft_lstnew(long content)
{
	t_list	*pointer;

	pointer = (t_list *)malloc(sizeof(t_list));
	if (!pointer)
		return (NULL);
	pointer->value = content;
	pointer->next = NULL;
	return (pointer);
}
