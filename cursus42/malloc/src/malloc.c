#include <stdio.h>
#include <stdlib.h>
#include "../inc/malloc.h"

t_page *alloc_page(size_t size)
{
	t_page *page;
	size_t page_size;

	page_size = get_size(size);
	page = (t_page*)mmap(NULL, page_size, PROT_READ | PROT_WRITE,
			MAP_PRIVATE | MAP_ANON, -1, 0);
	if (page == NULL)
		return (NULL);
	page->type = get_page_type(size);
	page->size = page_size - PAGE_SIZE;
	page->next = NULL;
	page->prev = NULL;
	page->block = NULL;
	link_page(page);
	return (page);
}
void	split_block(t_block *b, size_t mem_width)
{
	t_block	*nb;

	if (b->size + BLOCK_SIZE == mem_width)
		return ;
	nb = (t_block*)(BDATA(b) + b->size - 1);
	init_block(nb, mem_width - BLOCK_SIZE * 2 - b->size);
	nb->next = b->next;
	b->next = nb;
	nb->prev = b;
	nb->free = 1;
}
t_block *insert_block(t_page *page, size_t size)
{
	t_block *block;

	block = (t_block*)PDATA(page);
	if (block == NULL)
		return (NULL);
	init_block(block, size);
	if (page->type != LARGE)
		split_block(block, size);
	page->block = block;
	return (block);
}
t_block *extend_heap(size_t size)
{
	t_block *block;
	t_page *page;

	page = alloc_page(size);
	if (page == NULL)
		return (NULL);
	block = insert_block(page, size);
	if (block == NULL)
		return (NULL);
	return (block);
}
void	*ft_malloc(size_t size)
{
	t_block *base;

	base = NULL;
	base = search_free_space_in_page(size);
	if (base == NULL)
		base = extend_heap(size);
	if (base == NULL)
		return (NULL);
	return (BDATA(base));
}
int main(int argc, char **argv)
{
	char c;
	int nb;
	int i;
	char *str;
	char *str2;
	char *str3;
	char *str4;
	nb = atoi(argv[1]);
	c = argv[2][0];
	i  = 0;
	str = ft_malloc(nb + 1);
	while (i<nb)
	{
		str[i] = c;
		i++;
	}
	str[i] = 0;
	i  = 0;
	str2 = ft_malloc(nb + 1);
	while (i<nb)
	{
		str2[i] = c;
		i++;
	}
	str2[i] = 0;
	i  = 0;
	str3 = ft_malloc(nb + 1);
	while (i<nb)
	{
		str3[i] = c;
		i++;
	}
	str3[i] = 0;
	printf("%s\n%s\n%s\n", str, str2, str3);
	show_alloc_mem();
	ft_free(str);
	ft_free(str2);
	str4 = ft_malloc(1024*1024*1024);
	printf("free\n");
	show_alloc_mem();
	ft_free(str3);
	printf("free\n");
	show_alloc_mem();
	ft_free(str4);
	show_alloc_mem();
	printf("SIZEOF: %lu\n",sizeof(t_block));
	return (0);
}