/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 12:29:52 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/11 14:58:06 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	init_tab(int flags[9])
{
	flags[0] = 0;
	flags[1] = 0;
	flags[2] = 0;
	flags[3] = 0;
	flags[4] = 0;
	flags[5] = 0;
	flags[6] = 0;
	flags[7] = 0;
	flags[8] = 0;
	flags[9] = 0;
}

int		is_flag(char *str)
{
	int	flags[10];
	int i;

	i = 1;
	init_tab(flags);
	while (str[i] != '\0')
	{
		if (str[i] == 'l' && flags[0] == 0)
			flags[0] = 1;
		else if (str[i] == 'R' && flags[1] == 0)
			flags[1] = 1;
		else if (str[i] == 'a' && flags[2] == 0)
			flags[2] = 1;
		else if (str[i] == 'r' && flags[3] == 0)
			flags[3] = 1;
		else if (str[i] == 't' && flags[4] == 0)
			flags[4] = 1;
		else if (str[i] == 'u' && flags[5] == 0)
			flags[5] = 1;
		else if (str[i] == 'f' && flags[6] == 0)
			flags[6] = 1;
		else if (str[i] == 'g' && flags[7] == 0)
			flags[7] = 1;
		else if (str[i] == 'd' && flags[8] == 0)
			flags[8] = 1;
		else if (str[i] == '1' && flags[9] == 0)
			flags[9] = 1;
		else
			return (str[i + 1]);
		i++;
	}
	return (1);
}

void	attrib_flag(char *str, t_flag **flag)
{
	int i;

	i = 1;
	while (str[i] != '\0')
	{
		if (str[i] == 'l' && (*flag)->f_l == 0)
			(*flag)->f_l = 1;
		else if (str[i] == 'R' && (*flag)->f_R_maj == 0)
			(*flag)->f_R_maj = 1;
		else if (str[i] == 'a' && (*flag)->f_a == 0)
			(*flag)->f_a = 1;
		else if (str[i] == 'r' && (*flag)->f_r_min == 0)
			(*flag)->f_r_min = 1;
		else if (str[i] == 't' && (*flag)->f_t == 0)
			(*flag)->f_t = 1;
		else if (str[i] == 'u' && (*flag)->f_u == 0)
			(*flag)->f_u = 1;
		else if (str[i] == 'f' && (*flag)->f_f == 0)
			(*flag)->f_f = 1;
		else if (str[i] == 'g' && (*flag)->f_g == 0)
			(*flag)->f_g = 1;
		else if (str[i] == 'd' && (*flag)->f_d == 0)
			(*flag)->f_d = 1;
		else if (str[i] == '1' && (*flag)->f_un == 0)
			(*flag)->f_un = 1;
		i++;
	}
}
