/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 13:34:50 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/01 18:20:49 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		g_tt[3];
int		g_rajout;
int		g_char_nul;
int		g_s_maj;

int		run_var(char *str, char c)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

void	ft_cut_replace(char **str, int count[3])
{
	if (str[count[0]][0] == ' ' && ft_strlen(str[count[0]]) == 1 &&
			count[0] != 0)
		;
	else if (str[count[0]][0] == ' ' && ft_strlen(str[count[0]]) == 1 &&
			count[0] == 0)
		str[count[0]][0] = '\0';
}

void	ft_cut_replace2(char **str, t_var **var, va_list liste, int count[3])
{
	if (end_s == 'd' || end_s == 'i' || end_s == 'D')
		ft_cut_print_d1(var, str, count, liste);
	else if (end_s == 'u' || end_s == 'U')
		ft_cut_print_u1(var, str, count, liste);
	else if (end_s == 'c' || end_s == 'C')
		ft_cut_print_c1(var, str, count, liste);
	else if (end_s == 's' || end_s == 'S')
		ft_cut_print_s1(var, str, count, liste);
	else if (end_s == 'p')
		ft_cut_print_p1(var, str, count, liste);
	else if (end_s == 'x' || end_s == 'X')
		ft_cut_print_x1(var, str, count, liste);
	else if (end_s == 'o' || end_s == 'O')
		ft_cut_print_o1(var, str, count, liste);
}

void	replace_char(char **str, t_var **var, va_list liste, int *tab)
{
	int count[3];

	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	while (str[count[0]] != '\0')
	{
		if (is_indice(count[0], tab))
		{
			if (cmp_s1)
				ft_cut_print_spec(var, str, count, liste);
			else if (cmp_s2 || cmp_s3 || cmp_s4 || cmp_s5)
				str[count[0]] = ft_strdup("\0");
			else if (str[count[0]][0] == ' ' && ft_strlen(str[count[0]]) == 1)
				ft_cut_replace(str, count);
			else if (ft_isalpha_spec(end_s))
				ft_cut_replace2(str, var, liste, count);
			else if (ft_strlen(str[count[0]]) == 1 && str[count[0]][0] == 'P')
				str[count[0]][0] = '%';
			else
				ft_cut_print_else(str, count);
		}
		count[0]++;
	}
}

int		ft_printf(char *format, ...)
{
	va_list		liste;
	char		**str_split;
	char		*new_str;
	t_var		**var;
	int			n_v_p;
	int			size;
	int			i;
	int			retour;
	int			*tab;

	retour = 0;
	size = 0;
	i = 0;
	g_char_nul = -10;
	g_rajout = 0;
	g_s_maj = 0;
	size = ft_strlen(format);
	n_v_p = run_var(format, '%');
	size++;
	tab = (int *)malloc(sizeof(int) * 110);
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(format) + n_v_p * 4));
	var = (t_var **)malloc(sizeof(t_var) * n_v_p);
	while (i < n_v_p)
	{
		var[i] = (t_var *)malloc(sizeof(t_var));
		i++;
	}
	recover_percent(format, new_str, size, tab);
	str_split = ft_strsplit(new_str, '%');
	va_start(liste, format);
	replace_char(str_split, var, liste, tab);
	va_end(liste);
	i = 0;
	while (str_split[i])
	{
		if (str_split[i][0] == '.' &&
				ft_isdigit(str_split[i][1]) == 1 && g_s_maj != 1)
			str_split[i] = ft_strdup("%\0");
		if (i == g_char_nul)
			ft_putstr_spec(str_split[i]);
		else
			ft_putstr(str_split[i]);
		retour += ft_strlen(str_split[i]);
		i++;
	}
	retour += g_rajout;
	return (retour);
}
