#include "utils.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;
	size_t	total_size;

	total_size = count * size;
	mem = malloc(total_size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, total_size);
	return (mem);
}