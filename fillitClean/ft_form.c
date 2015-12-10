/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_form.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 13:14:45 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/08 17:27:16 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_esp_23(int esp[5])
{
	if (esp[3] == g_len_mx)
	{
		if (esp[4] == 2 * g_len_mx - 1)
			return (7);
		else
			return (2);
	}
	else if (esp[3] == g_len_mx + 1)
	{
		if (esp[4] == 2 * g_len_mx + 1)
			return (8);
		else
			return (5);
	}
	return (0);
}

int	check_form_23(int esp[5])
{
	if (esp[0] == 1)
	{
		if (esp[3] == g_len_mx + 1)
			return (1);
		else if (esp[3] == g_len_mx)
			return (4);
	}
	else if (esp[1] == 1)
		return (check_esp_23(esp));
	else if (esp[2] == 1)
	{
		if (esp[3] == 2 * g_len_mx - 1)
			return (3);
		else if (esp[3] == 2 * g_len_mx)
			return (6);
	}
	return (0);
}

int	check_form_32(int esp[5])
{
	if (esp[0] == 1)
	{
		if (esp[1] == g_len_mx)
			return (8);
		else if (esp[1] == g_len_mx - 2)
			return (7);
		else if (esp[4] == g_len_mx + 1)
			return (2);
		else if (esp[4] == g_len_mx)
			return (1);
		else if (esp[4] == g_len_mx + 2)
			return (3);
	}
	else if (esp[0] == g_len_mx)
		return (4);
	else if (esp[0] == g_len_mx - 1)
		return (5);
	else if (esp[0] == g_len_mx - 2)
		return (6);
	return (0);
}

int	return_form(int *t1, int taille, int indice, int esp[5])
{
	if (indice == 1)
	{
		if (t1[0] / taille <= taille - 4)
			return (1);
	}
	else if (indice == 2)
		return (check_pos_23(check_form_23(esp), t1));
	else if (indice == 3)
	{
		if (t1[0] % taille < taille - 1 && t1[0] / taille < taille - 1)
		{
			if (t1[3] / taille > 0 && t1[3] % taille > 0)
				return (1);
		}
	}
	else if (indice == 4)
		return (check_pos_32(check_form_32(esp), t1));
	else if (indice == 5)
	{
		if (t1[0] % taille == 0)
			return (1);
	}
	return (0);
}

int	keep_form(int *t1, int *spc, int taille)
{
	int esp[5];

	esp[0] = t1[1] - t1[0];
	esp[1] = t1[2] - t1[1];
	esp[2] = t1[3] - t1[2];
	esp[3] = t1[2] - t1[0];
	esp[4] = t1[3] - t1[0];
	if (spc[0] == 1)
		return (return_form(t1, taille, 1, esp));
	else if (spc[0] == 2 && spc[1] == 3)
		return (return_form(t1, taille, 2, esp));
	else if (spc[0] == 2 && spc[1] == 2)
		return (return_form(t1, taille, 3, esp));
	else if (spc[0] == 3 && spc[1] == 2)
		return (return_form(t1, taille, 4, esp));
	else if (spc[0] == 4)
		return (return_form(t1, taille, 5, esp));
	return (0);
}
