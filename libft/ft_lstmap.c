#include "libft.h"

static void	del(void *content)
{
	free(content);
}

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newls;
	t_list	*node;

	if (!lst)
		return (NULL);
	newls = NULL;
	while (lst)
	{
		if (!f)
			node = ft_lstnew(lst->content, lst->content_size);
		else
			node = ft_lstnew(f(lst->content), lst->content_size);
		if (!node)
		{
			ft_lstclear(&newls, del);
			return (NULL);
		}
		ft_lstadd(&newls, node);
		lst = lst->next;
	}
	return (newls);
}
