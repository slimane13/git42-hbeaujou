/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choix_boucle_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 18:40:45 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/08 18:43:19 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	lance_boucle_14_2(int nbr, int flag[26], int nbr_courant[26])
{
	if (nbr == 10)
	{
		nbr_courant[10] = -1;
		ft_boucle_f10_big(flag, nbr_courant);
	}
	else if (nbr == 11)
	{
		nbr_courant[11] = -1;
		ft_boucle_f11_big(flag, nbr_courant);
	}
	else if (nbr == 12)
	{
		nbr_courant[12] = -1;
		ft_boucle_f12_big(flag, nbr_courant);
	}
	else if (nbr == 13)
	{
		nbr_courant[13] = -1;
		ft_boucle_f13_big(flag, nbr_courant);
	}
}

void	lance_boucle_59_2(int nbr, int flag[26], int nbr_courant[26])
{
	if (nbr == 14)
	{
		nbr_courant[14] = -1;
		ft_boucle_f14_big(flag, nbr_courant);
	}
	else if (nbr == 15)
	{
		nbr_courant[15] = -1;
		ft_boucle_f15_big(flag, nbr_courant);
	}
	else if (nbr == 16)
	{
		nbr_courant[16] = -1;
		ft_boucle_f16_big(flag, nbr_courant);
	}
	else if (nbr == 17)
	{
		nbr_courant[17] = -1;
		ft_boucle_f17_big(flag, nbr_courant);
	}
	else if (nbr == 18)
	{
		nbr_courant[18] = -1;
		ft_boucle_f18_big(flag, nbr_courant);
	}
}
