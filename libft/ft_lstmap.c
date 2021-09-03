#include "libft.h"

// t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
// {
// 	t_list	*pointer;
// 	t_list	*begin;

// 	begin = NULL;
// 	while (lst)
// 	{
// 		pointer = ft_lstnew(f(lst->content));
// 		if (!pointer)
// 		{
// 			ft_lstclear(&begin, del);
// 			break ;
// 		}
// 		ft_lstadd_back(&begin, pointer);
// 		lst = lst->next;
// 	}
// 	return (begin);
// }
