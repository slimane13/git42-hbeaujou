/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 13:08:18 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/08/19 13:08:31 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_malloc.h>

char			is_pointer_in_page(void *page, void *ptr)
{
	int			*int_mem;

	int_mem = (int *)(page + 1);
	if (ptr > page && ptr < (page + (*int_mem)))
		return (1);
	else
		return (0);
}

void			*realloc_less_size(int *ptr, size_t size)
{
	char		*mem;
	int			i;

	mem = (char *)(ptr + 1);
	i = (int)size;
	// ft_bzero ????
	while (i < *ptr)
		mem[i++] = 0;
	*ptr = (int)size;
	return ((void *)mem);
}

void			*go_elsewhere(void *old_ptr, size_t size, int old_size)
{
	void		*new_ptr;

	new_ptr = malloc(size);
	if (!new_ptr)
		return (NULL);
	new_ptr = ft_memcpy(new_ptr, old_ptr, (size_t)old_size);
	free(old_ptr);
	return (new_ptr);
}

void			*realloc_page(void *mem, int page_size, void *ptr, size_t size)
{
	int			i;
	int			*ptr_old_size;
	int			*int_ptr;

	ptr_old_size = (int *)(ptr - 4);
	if ((int)size < *ptr_old_size)
		return (realloc_less_size(ptr_old_size, size));
	i = *ptr_old_size;
	while (i < ((int)size) && i + 3 < (page_size - (int)(ptr - mem)))
	{
		int_ptr = (int *)(ptr + i);
		if (*int_ptr != 0)
			return (go_elsewhere(ptr, size, *ptr_old_size));
		i++;
	}
	if (i == (int)size)
		*ptr_old_size = (int)size;
	else
		return (go_elsewhere(ptr, size, *ptr_old_size));
	return (ptr);
}

void			*realloc(void *ptr, size_t size)
{
	char		*char_ptr;
	char		*mem;
	char		**ptr_mem;
	int			*int_mem;

	ft_putstr("trying to realloc\n");
	char_ptr = (char *)ptr;
	mem = get_malloc(0, size);
	while (mem != NULL)
	{
		ptr_mem = (char **)(mem + 5);
		if (is_pointer_in_page(mem, ptr) == 1)
		{
			int_mem = (int *)(mem + 1);
			return (realloc_page(mem, *int_mem, ptr, size));
		}
		mem = *ptr_mem;
	}
	return (NULL);
}
