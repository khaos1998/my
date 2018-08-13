#include "../inc/malloc.h"

void print_block(t_block *block)
{
	if (block == NULL || block->free == 1)
		return ;
	printf("%p-%p: %lu octets\n", BDATA(block), BDATA(block) + block->size, block->size);
}
void show_alloc_mem(void)
{
	t_page *page;
	t_block *block;

	page = g_head;
	if (page == NULL)
	{
		puts("No memory alloc\n");
		return ;
	}
	while (page != NULL)
	{
		printf("Page: %p type:", page);
		if (page->type == TINY)
			puts("TYNE");
		else if (page->type == SMALL)
			puts("SMALL");
		else
			puts("LARGE");
		block = page->block;
		while (block != NULL)
		{
			print_block(block);
			block = block->next;
		} 
		page = page->next;
	}
}