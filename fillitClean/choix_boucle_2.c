/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choix_boucle_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 18:40:45 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/08 18:44:24 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	lance_boucle_14_2(int nbr, int flag[26], int g_nbr_crt[26])
{
	if (nbr == 10)
	{
		g_nbr_crt[10] = -1;
		ft_boucle_f10_big(flag, g_nbr_crt);
	}
	else if (nbr == 11)
	{
		g_nbr_crt[11] = -1;
		ft_boucle_f11_big(flag, g_nbr_crt);
	}
	else if (nbr == 12)
	{
		g_nbr_crt[12] = -1;
		ft_boucle_f12_big(flag, g_nbr_crt);
	}
	else if (nbr == 13)
	{
		g_nbr_crt[13] = -1;
		ft_boucle_f13_big(flag, g_nbr_crt);
	}
}

void	lance_boucle_59_2(int nbr, int flag[26], int g_nbr_crt[26])
{
	if (nbr == 14)
	{
		g_nbr_crt[14] = -1;
		ft_boucle_f14_big(flag, g_nbr_crt);
	}
	else if (nbr == 15)
	{
		g_nbr_crt[15] = -1;
		ft_boucle_f15_big(flag, g_nbr_crt);
	}
	else if (nbr == 16)
	{
		g_nbr_crt[16] = -1;
		ft_boucle_f16_big(flag, g_nbr_crt);
	}
	else if (nbr == 17)
	{
		g_nbr_crt[17] = -1;
		ft_boucle_f17_big(flag, g_nbr_crt);
	}
	else if (nbr == 18)
	{
		g_nbr_crt[18] = -1;
		ft_boucle_f18_big(flag, g_nbr_crt);
	}
}
