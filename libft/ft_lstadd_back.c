#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{	
	t_list	*pointer;

	pointer = *lst;
	if (!new)
		return ;
	if (*lst)
	{
		while (pointer->next)
			pointer = pointer->next;
		pointer->next = new;
	}
	else
		*lst = new;
}
