#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*list;

	if (lst)
	{
		tmp = lst;
		list = ft_lstnew(f(tmp->content));
		if (!list)
			return (NULL);
		tmp = tmp->next;
		while (tmp)
		{
			new = ft_lstnew(f(tmp->content));
			if (!new)
			{
				ft_lstclear(&list, del);
				return (NULL);
			}
			ft_lstadd_back(&list, new);
			tmp = tmp->next;
		}
		return (list);
	}
	return (NULL);
}
