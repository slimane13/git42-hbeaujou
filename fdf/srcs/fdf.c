/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 12:31:14 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/08 14:15:22 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(void)
{
	t_point	*tmp;
	t_point *begin_p;
	t_line	*tmp2;
	t_line	*begin_l;
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


	done = 0;
	j = 0;
	str = NULL;
	begin_p = NULL;
	tmp = NULL;
	begin_l = NULL;
	while (done != 1)
	{
		i = 0;
		k = 0;
		get_next_line(0, &line);
		if (j == 11)
			done = 1;
		str = ft_strsplit(line, ' ');
		begin_p = NULL;
		while (str[k])
		{
			tmp = new_point(i, j, ft_atoi(str[k]));
			ft_lstaddend_point(&begin_p, tmp);
			i++;
			k++;
		}
		tmp2 = new_line(begin_p);
		ft_lstaddend_line(&begin_l, tmp2);
		j++;
	}
	
	if (!(init = mlx_init()))
		return (0);

	window = mlx_new_window (init, 200, 200 , "TEST FDP");
	
	tmp2 = begin_l;
	while (tmp2)
	{
		tmp = tmp2->line;
		while (tmp)
		{
			if (tmp->h != 0)
				mlx_pixel_put(init, window, 5 * tmp->x + 20, 5 * tmp->y + 20, 0xFF0000);
			tmp = tmp->next;
		}
		tmp2 = tmp2->next;
	}
	
	mlx_loop(init);
	return (0);
}
