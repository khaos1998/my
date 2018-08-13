#include "../inc/malloc.h"
void	*realloc(void *ptr, size_t size)
{
	void	*to_return;
	t_block *block;

	block = search_ptr(ptr);
	to_return = malloc(size);
	if (block != NULL)
	{
		block->free = 1;
		ft_memcpy(to_return, BDATA(block), size);
	}
	return (to_return);
}