#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*pointer;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		pointer = *lst;
		del((*lst)->content);
		*lst = (*lst)->next;
		free(pointer);
	}
	lst = NULL;
}
