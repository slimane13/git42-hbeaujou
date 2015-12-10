/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choix_boucle_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 18:36:00 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/08 18:39:41 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	lance_boucle_14(int nbr, int flag[26], int g_nbr_crt[26])
{
	if (nbr == 1)
	{
		g_nbr_crt[1] = -1;
		ft_boucle_f1_special(flag, g_nbr_crt);
	}
	else if (nbr == 2)
	{
		g_nbr_crt[2] = -1;
		ft_boucle_f2_special(flag, g_nbr_crt);
	}
	else if (nbr == 3)
	{
		g_nbr_crt[3] = -1;
		ft_boucle_f3_big(flag, g_nbr_crt);
	}
	else if (nbr == 4)
	{
		g_nbr_crt[4] = -1;
		ft_boucle_f4_big(flag, g_nbr_crt);
	}
}

void	lance_boucle_59(int nbr, int flag[26], int g_nbr_crt[26])
{
	if (nbr == 5)
	{
		g_nbr_crt[5] = -1;
		ft_boucle_f5_big(flag, g_nbr_crt);
	}
	else if (nbr == 6)
	{
		g_nbr_crt[6] = -1;
		ft_boucle_f6_big(flag, g_nbr_crt);
	}
	else if (nbr == 7)
	{
		g_nbr_crt[7] = -1;
		ft_boucle_f7_big(flag, g_nbr_crt);
	}
	else if (nbr == 8)
	{
		g_nbr_crt[8] = -1;
		ft_boucle_f8_big(flag, g_nbr_crt);
	}
	else if (nbr == 9)
	{
		g_nbr_crt[9] = -1;
		ft_boucle_f9_big(flag, g_nbr_crt);
	}
}
