/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 13:34:50 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/01 20:33:42 by hbeaujou         ###   ########.fr       */
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
	if (END_S == 'd' || END_S == 'i' || END_S == 'D')
		ft_cut_print_d1(var, str, count, liste);
	else if (END_S == 'u' || END_S == 'U')
		ft_cut_print_u1(var, str, count, liste);
	else if (END_S == 'c' || END_S == 'C')
		ft_cut_print_c1(var, str, count, liste);
	else if (END_S == 's' || END_S == 'S')
		ft_cut_print_s1(var, str, count, liste);
	else if (END_S == 'p')
		ft_cut_print_p1(var, str, count, liste);
	else if (END_S == 'x' || END_S == 'X')
		ft_cut_print_x1(var, str, count, liste);
	else if (END_S == 'o' || END_S == 'O')
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
			if (CMP_S1)
				ft_cut_print_spec(var, str, count, liste);
			else if (CMP_S2 || CMP_S3 || CMP_S4 || CMP_S5)
				str[count[0]] = ft_strdup("\0");
			else if (str[count[0]][0] == ' ' && ft_strlen(str[count[0]]) == 1)
				ft_cut_replace(str, count);
			else if (ft_isalpha_spec(END_S))
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
	t_var		**var;
	t_main		t_m;

	ft_cut_main(&t_m, format);
	t_m.n_v_p = run_var(format, '%');
	t_m.size++;
	t_m.tab = (int *)malloc(sizeof(int) * 110);
	t_m.new_str = (char *)malloc(sizeof(char) *
			(ft_strlen(format) + t_m.n_v_p * 4));
	var = (t_var **)malloc(sizeof(t_var) * t_m.n_v_p);
	while (t_m.i < t_m.n_v_p)
	{
		var[t_m.i] = (t_var *)malloc(sizeof(t_var));
		t_m.i++;
	}
	recover_percent(format, t_m.new_str, t_m.size, t_m.tab);
	t_m.str_split = ft_strsplit(t_m.new_str, '%');
	va_start(liste, format);
	replace_char(t_m.str_split, var, liste, t_m.tab);
	va_end(liste);
	t_m.i = 0;
	ft_affiche(&t_m);
	t_m.retour += g_rajout;
	return (t_m.retour);
}
