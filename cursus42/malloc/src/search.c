#include "../inc/malloc.h"

t_block *search_free_space_in_block(size_t size)
{
	t_block		*b;

	b = g_head->block;
	while (b != NULL && !(b->free && b->size >= size))
		b = b->next;
	return (b);
}

t_block *search_free_space_in_page(size_t size)
{
	t_type type;
	t_block *ret;
	t_page *head;
	size_t		mem;

	type = get_page_type(size);
	head = g_head;
	ret = NULL;
	while (head != NULL)
	{
		if (type == head->type)
		{
			if ((ret = search_free_space_in_block(size)) != NULL)
				break;
		}
		head = head->next;
	}
	if (ret == NULL)
		return (NULL);
	mem = ret->size + BLOCK_SIZE;
	ret->size = size;
	split_block(ret, mem);
	ret->free = 0;
	return (ret);
}

t_block *search_block(void *ptr)
{
	t_page *page;
	t_block *block;

	page = g_head;
	while (page != NULL)
	{
		if ((block = search_in_page(page, ptr)) != NULL)
			return (block);
		page = page->next;
	}
	return (NULL);
}

t_block *search_in_page(t_page *page, void *ptr)
{
	t_block *block;

	block = page->block;
	while (block != NULL)
	{
		if (ptr == BDATA(block))
			return (block);
		block = block->next;
	}
	return (NULL);
}