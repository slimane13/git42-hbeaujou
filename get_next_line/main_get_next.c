/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 16:45:09 by tvermeil          #+#    #+#             */
/*   Updated: 2015/12/14 19:40:57 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "libft.h"

int		is_finished(int *return_val, int ac)
{
	while (ac--)
		if (return_val[ac] == 1)
			return (0);
	return (1);
}

void	read_stdin(char	*line)
{
	int		nbr;

	while ((nbr = get_next_line(0, &line)) != 0)
	{
		if (nbr == -1)
		{
			ft_putendl("erreur lors de la lecture");
			return ;
		}
		ft_putendl(line);
	}
}
int		main(int ac, char **av)
{
	int		fd[ac];
	int		return_val[ac];
	char	*line;
	int		i;

	line = NULL;
	if (ac == 1)
	{
		read_stdin(line);
		return (0);
	}
	i = 0;
	while (++i < ac)
	{
		fd[i - 1] = open(av[i], O_RDONLY);
		if (fd[i - 1] == -1)
		{
			ft_putendl("erreur lors de l'ouverture du fichier");
			return (-1);
		}
		return_val[i - 1] = 1;
	}
	i = 0;
	while (!is_finished(return_val, ac))
	{
		return_val[i] = get_next_line(fd[i], &line);
		if (return_val[i] == 1)
			ft_putendl(line);
		i++;
		if (i == ac - 1)
			i = 0;
		free(line);
	}
}
