#ifndef MALLOC_H
#define MALLOC_H

#include <sys/mman.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

# define BLOCK_SIZE	(sizeof(t_block))
# define BDATA(b)	((void*)((char*)b + sizeof(t_block) + 1))

# define PAGE_SIZE	(sizeof(t_page))
# define PDATA(p)	((void*)((char*)p + sizeof(t_page) + 1))

# define TINY_LENGTH		(2 * getpagesize())
# define TINY_MAX_ALLOC		128

# define SMALL_LENGTH		(16 * getpagesize())
# define SMALL_MAX_ALLOC	1024

typedef enum e_type
{
	TINY,
	SMALL,
	LARGE
}			t_type;
typedef struct s_block
{
	struct 		s_block *next;
	struct 		s_block *prev;
	int 		free;
	size_t		size;
	void 		*ptr;
}				t_block;

typedef struct s_page
{
	struct s_page *next;
	struct s_page *prev;
	size_t 			size;
	t_block			*block;
	t_type 			type;
}				t_page;

t_page *g_head;

/*
** malloc.c
*/
void	*ft_malloc(size_t size);
t_block *extend_heap(size_t size);
t_block *insert_block(t_page *page, size_t size);
void	split_block(t_block *b, size_t mem_width);
t_page *alloc_page(size_t size);

/*
**  free.c
*/

t_block	*fusion_block(t_block *beg);
void		del_page(t_page *page);
void	check_page(t_block *b);
t_page		*block_parent_page(t_block *b);
void ft_free(void *ptr);

/*
** realloc.c
*/
void	*realloc(void *ptr, size_t size)

/*
** search.c
*/

t_block *search_in_page(t_page *page, void *ptr);
t_block *search_block(void *ptr);
t_block *search_free_space_in_page(size_t size);
t_block *search_free_space_in_block(size_t size);

/*
** show_mem.c
*/

void show_alloc_mem(void);
void print_block(t_block *block);

/*
** utils.c
*/

void link_page(t_page *page);
size_t get_size(size_t size);
void		init_block(t_block *block, size_t size);
t_type 	get_page_type(size_t size);
#endif