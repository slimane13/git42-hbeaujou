/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 12:31:14 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/02/02 11:04:20 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_point	*tmp;
	t_point *begin_p;
	void	*init;
	void	*window;
	char	*line;
	char	**str;
	int		ret;
	int		i;
	int		j;
	int		k;
	int		x;
	int		y;
	int		done;
	int		fd;

	done = 0;
	j = 0;
	str = NULL;
	begin_p = NULL;
	tmp = NULL;
	fd = open(argv[1], O_RDONLY);
	if (argc == 3)
		;
	///////////////////////////// RECUP FILE ////////////////////////
	while (done != 1)
	{
		i = 0;
		k = 0;
		get_next_line(fd, &line);
		if (ft_strcmp(line, "\n") == 0 || ft_strcmp(line, "\0") == 0)
			done = 1;
		str = ft_strsplit(line, ' ');
		while (str[k])
		{
			tmp = new_point(i, j, ft_atoi(str[k]));
			ft_lstaddend_point(&begin_p, tmp);
			i++;
			k++;
		}
		j++;
	}
	if (!(init = mlx_init()))
		return (0);
	///////////////////////////// FENETRE /////////////////////////
	window = mlx_new_window (init, 800, 800 , "TEST FDP");
	///////////////////// AFFICHAGE DES PIXELS ////////////////////
	tmp = begin_p;
	while (tmp)
	{
		ft_printf("x : %d - y : %d - z : %d\n", tmp->x, tmp->y, tmp->z);
		if (tmp->z != 0)
			mlx_pixel_put(init, window, 5 * tmp->x, 5 * tmp->y, 0xFF0000);
		tmp = tmp->next;
	}
	////////////////////////// INPUT //////////////////////////////
	mlx_hook(window, 2, 3, key_hook, &begin_p);	
	//////////////////////////// LOOP /////////////////////////////
	mlx_loop(init);
	return (0);
}
