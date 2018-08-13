# include "../inc/malloc.h"

t_block	*fusion_block(t_block *beg)
{
	t_block	*end;

	end = beg;
	while (beg->prev != NULL && beg->prev->free)
		beg = beg->prev;
	while (end->next != NULL && end->next->free)
		end = end->next;
	if (beg == end)
	{
		beg->free = 1;
		return (beg);
	}
	beg->size = BDATA(end) + end->size - BDATA(beg);
	beg->next = end->next;
	beg->free = 1;
	return (beg);
}
void		del_page(t_page *page)
{
	if (page->prev == NULL && page->next)
		g_head = NULL;
	if (page->prev != NULL)
		page->prev->next = page->next;
	else
		g_head = page->next;
	if (page->next != NULL)
		page->next->prev = page->prev;
	munmap(page, page->size + PAGE_SIZE);
}

void	check_page(t_block *b)
{
	t_page	*page;
	t_block	*first;

	page = block_parent_page(b);
	first = page->block;
	if (first != NULL &&
			first->free &&
			first->next == NULL)
		del_page(page);
}
t_page		*block_parent_page(t_block *b)
{
	t_page	*iter;

	if (b == NULL)
		return (NULL);
	iter = g_head;
	while ((void*)iter < (void*)b)
	{
		if ((void*)iter < (void*)b && PDATA(iter) + iter->size > (void*)b)
			return (iter);
		iter = iter->next;
	}
	return (NULL);
}
void ft_free(void *ptr)
{
	t_block *block;

	if (ptr == NULL)
		return ;
	block = search_block(ptr);
	if (block == NULL)
		return ;
	block = fusion_block(block);
	check_page(block);
}