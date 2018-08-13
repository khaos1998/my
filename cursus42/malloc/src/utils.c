#include "../inc/malloc.h"
t_type 	get_page_type(size_t size)
{
	if (size <= TINY_LENGTH)
		return (TINY);
	if (size <= SMALL_LENGTH)
		return (SMALL);
	return (LARGE);
}

void		init_block(t_block *block, size_t size)
{
	block->size = size;
	block->next = NULL;
	block->prev = NULL;
	block->free = 0;
}

size_t get_size(size_t size)
{
	if (size <= TINY_MAX_ALLOC)
		return (TINY_LENGTH);
	if (size <= SMALL_MAX_ALLOC)
		return (SMALL_LENGTH);
	return (size + PAGE_SIZE);
}

void link_page(t_page *page)
{
	t_page *head;

	if (g_head == NULL)
		g_head = page;
	else
	{
		head = g_head;
		while (head->next != NULL)
			head = head->next;
		head->next = page;
		page->prev = head;
	}
}