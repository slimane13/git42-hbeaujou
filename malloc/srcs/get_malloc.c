/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_malloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 12:38:13 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/08/19 12:38:14 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_malloc.h>

#define FLAGS PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE

void				*get_malloc(char init, size_t size)
{
	static void		*pages = NULL;

	ft_putstr("--------- get_malloc_begin --------- \n");
	if (init == 1)
		pages = NULL;
	if (!pages && init != 1 && size > 0)
		pages = get_page(size, 1);
	ft_putstr("--------- get_malloc_end ----------- \n");
	return (pages);
}

char				test_rlimit(size_t size)
{
	char			*mem;
	char			**ptr_mem;
	int				total;
	int				*int_mem;
	struct rlimit	rlp;

	total = 0;
	getrlimit(RLIMIT_AS, &rlp);
	mem = get_malloc(0, size);
	while (mem != NULL)
	{
		ptr_mem = (char **)(mem + 5);
		int_mem = (int *)(mem + 1);
		total += *int_mem;
		mem = *ptr_mem;
	}
	if ((unsigned long long)(total + get_max_type_size(size)) <= rlp.rlim_cur)
		return (0);
	return (1);
}

void				*get_page(size_t size, int init)
{
	char			*mem;
	int				*mem2;
	char			**mem3;

	ft_putstr("********* get_page_begin ********* \n");
	if (init == 0 && test_rlimit(size) == 1)
		return (NULL);
	mem = (char *)mmap(0, get_max_type_size(size), FLAGS, -1, 0);
	ft_bzero(mem, get_max_type_size(size));
	mem[0] = get_type(size);
	mem2 = (int *)(mem + 1);
	mem2[0] = get_max_type_size(size);
	mem3 = (char **)(mem + 5);
	mem3[0] = NULL;
	ft_putstr("********* get_page_end *********** \n");
	return (mem);
}

void				*book_into_page(char *mem, size_t size)
{
	int				i;
	int				*int_mem;

	i = 13;
	while (i < (get_max_type_size(size) - (int)size))
	{
		int_mem = (int *)(mem + i);
		if (*int_mem == 0)
		{
			int_mem[0] = (int)size;
			return (mem + i + 4);
		}
		i += *int_mem;
		i += 4;
	}
	return (NULL);
}

void				*book_it(size_t size)
{
	char			*mem;
	char			**ptr_mem;
	void			*ret;

	ft_putstr("trying to get memory via malloc\n");
	mem = (char *)get_malloc(0, size);
	ft_putstr("pointeur sur memoire get pour ");
	ft_putnbr(size);
	ft_putchar('\n');
	while (mem != NULL)
	{
		if (get_type(size) == *mem)
		{
			ft_putstr("les pages sont bonnes, cela alloue\n");
			ret = book_into_page(mem, size);
			if (ret != NULL)
			{
				ft_putstr("les pages sont book\n\n");
				return (ret);
			}
		}
		ptr_mem = (char **)(mem + 5);
		if (!*ptr_mem)
			ptr_mem[0] = get_page(size, 0);
		mem = *ptr_mem;
	}
	return (NULL);
}
