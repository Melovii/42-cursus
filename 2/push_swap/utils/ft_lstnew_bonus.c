#include "utils.h"

t_list	*ft_lstnew(long int content)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	// list->content = (void *)content;
	list->content = content;
	list->next = NULL;
	return (list);
}
