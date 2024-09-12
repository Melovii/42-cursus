#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;

	if (*alst != NULL && del)
	{
		while (*alst)
		{
			temp = *alst;
			*alst = (*alst)->next;
			del(temp->content, temp->content_size);
			free(temp);
		}
		*alst = NULL;
	}
}
