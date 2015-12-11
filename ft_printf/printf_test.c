/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 12:48:44 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/11 16:52:59 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		run_var(char *str)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			count++;
		i++;
	}
	return (count);
}

void	recover(char *format, char *str, int len)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < len)
	{
		if (format[i] == '%')
		{
			str[j] = '%';
			j++;
			i++;
			str[j] = format[i];
			j++;
			str[j] = '%';
		}
		else
			str[j] = format[i];
		i++;
		j++;
	}
	str[j] = '\0';
}

void	recup_var(t_var **tab, int nbr_var, va_list liste)
{
	int i;

	i = 0;
	while (i < nbr_var)
	{
		tab[i]->entier = va_arg(liste, int);
		i++;
	}
}

void	replace_char(char **str, t_var **var)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'd')
			{
				str[i] = (char *)malloc(sizeof(char) * 3);
				str[i] = ft_itoa(var[count]->entier);
				str[i][2] = '\0';
				count++;
			}
			j++;
		}
		i++;
	}
}

void	ft_printf(char *format ,...)
{
	va_list		liste;
	char		**str_split;
	char		*new_str;
	t_var		**var;
	int			nbr_var;
	int			size;
	int			i;

	size = 0;
	i = 0;
	
	size = ft_strlen(format);
	nbr_var = run_var(format);
	size++;

	new_str = (char *)malloc(sizeof(char) * (ft_strlen(format) + nbr_var * 2));
	var = (t_var **)malloc(sizeof(t_var) * nbr_var);  /// REMPLISSAGE TABLEAU VAR, A FAIRE AVEC STRUCT
	while (i < nbr_var)
	{
		var[i] = (t_var *)malloc(sizeof(t_var));
		i++;
	}
	va_start(liste, format);

	recup_var(var, nbr_var, liste);
	recover(format, new_str, size);
	str_split = ft_strsplit(new_str, '%');
	replace_char(str_split, var);

	i = 0;
	while (str_split[i])
	{	
		ft_putstr(str_split[i]);
		i++;
	}

	va_end(liste);
}

int		main(void)
{
	int i;
	int i2;
	int i3;
	int i7;
	char c;
	char c2;

	i = 14;
	i2 = 21;
	i3 = 34;
	i7 = 84;
	c2 = 'F';
	ft_printf("i7 = %d\ni = %d\ni2 = %d\ni3 = %d\n", i7, i, i2, i3);
}
