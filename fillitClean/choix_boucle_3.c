/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choix_boucle_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 18:46:13 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/08 18:48:45 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	lance_boucle_14_3(int nbr, int flag[26], int g_nbr_crt[26])
{
	if (nbr == 19)
	{
		g_nbr_crt[19] = -1;
		ft_boucle_f19_big(flag, g_nbr_crt);
	}
	else if (nbr == 20)
	{
		g_nbr_crt[20] = -1;
		ft_boucle_f20_big(flag, g_nbr_crt);
	}
	else if (nbr == 21)
	{
		g_nbr_crt[21] = -1;
		ft_boucle_f21_big(flag, g_nbr_crt);
	}
	else if (nbr == 22)
	{
		g_nbr_crt[22] = -1;
		ft_boucle_f22_big(flag, g_nbr_crt);
	}
}

void	lance_boucle_59_3(int nbr, int flag[26], int g_nbr_crt[26])
{
	if (nbr == 23)
	{
		g_nbr_crt[23] = -1;
		ft_boucle_f23_big(flag, g_nbr_crt);
	}
	else if (nbr == 24)
	{
		g_nbr_crt[24] = -1;
		ft_boucle_f24_big(flag, g_nbr_crt);
	}
	else if (nbr == 25)
	{
		g_nbr_crt[25] = -1;
		ft_boucle_f25_big(flag, g_nbr_crt);
	}
	else if (nbr == 26)
	{
		g_nbr_crt[26] = -1;
		ft_boucle_f26_big(flag, g_nbr_crt);
	}
}
