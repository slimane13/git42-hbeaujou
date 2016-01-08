/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 15:54:53 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/08 16:16:42 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int	main(void)
{
	struct dirent	*read;
	struct stat		stats;

	stat("test7.txt", &stats);
	read = readdir(opendir("."));
	ft_printf("%s\n", read->d_name);
	ft_printf("%u\n", stats.st_size);
	return (0);
}
