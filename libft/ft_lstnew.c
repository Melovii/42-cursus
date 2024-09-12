#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	list = ft_memalloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->content = (void *)content;
	if (content == NULL)
		list->content_size = 0;
	else
		list->content_size = content_size;
	list->next = NULL;
	return (list);
}
