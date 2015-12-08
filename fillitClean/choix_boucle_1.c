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

void	lance_boucle_14(int nbr, int flag[26], int nbr_courant[26])
{
	if (nbr == 1)
	{
		nbr_courant[1] = -1;
		ft_boucle_f1_special(flag, nbr_courant);
	}
	else if (nbr == 2)
	{
		nbr_courant[2] = -1;
		ft_boucle_f2_special(flag, nbr_courant);
	}
	else if (nbr == 3)
	{
		nbr_courant[3] = -1;
		ft_boucle_f3_big(flag, nbr_courant);
	}
	else if (nbr == 4)
	{
		nbr_courant[4] = -1;
		ft_boucle_f4_big(flag, nbr_courant);
	}
}

void	lance_boucle_59(int nbr, int flag[26], int nbr_courant[26])
{
	if (nbr == 5)
	{
		nbr_courant[5] = -1;
		ft_boucle_f5_big(flag, nbr_courant);
	}
	else if (nbr == 6)
	{
		nbr_courant[6] = -1;
		ft_boucle_f6_big(flag, nbr_courant);
	}
	else if (nbr == 7)
	{
		nbr_courant[7] = -1;
		ft_boucle_f7_big(flag, nbr_courant);
	}
	else if (nbr == 8)
	{
		nbr_courant[8] = -1;
		ft_boucle_f8_big(flag, nbr_courant);
	}
	else if (nbr == 9)
	{
		nbr_courant[9] = -1;
		ft_boucle_f9_big(flag, nbr_courant);
	}
}
