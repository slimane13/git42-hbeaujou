/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 13:34:50 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/12 18:22:39 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	replace_char(char **str, t_var **var, va_list liste)
{
	int count[3];

	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	while (str[count[0]] != '\0')
	{
		if (count[0]%2 == 1)
		{
			if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'd')
			{
				var[count[2]]->entier = va_arg(liste, int);
				attrib_alpha(str, var, count);
			}
			else if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'c')
			{
				var[count[2]]->string = ft_itoa(va_arg(liste, int));
				attrib_alpha(str, var, count);
			}
			else if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 's')
			{
				var[count[2]]->string = va_arg(liste, char *);
				attrib_alpha(str, var, count);
			}
		}
		count[0]++;
	}
}

void	ft_printf(char *format ,...)
{
	va_list		liste;
	char		**str_split;
	char		*new_str;
	t_var		**var;
	int			nbr_var_percent;
	int			size;
	int			i;

	size = 0;
	i = 0;
	
	size = ft_strlen(format);
	nbr_var_percent = run_var(format, '%');
	size++;

	new_str = (char *)malloc(sizeof(char) * (ft_strlen(format) + nbr_var_percent * 2));
	var = (t_var **)malloc(sizeof(t_var) * nbr_var_percent);
	while (i < nbr_var_percent)
	{
		var[i] = (t_var *)malloc(sizeof(t_var));
		i++;
	}
	recover_percent(format, new_str, size);
	str_split = ft_strsplit(new_str, '%');
	va_start(liste, format);
	replace_char(str_split, var, liste);
	va_end(liste);

	i = 0;
	while (str_split[i])
	{	
		ft_putstr(str_split[i]);
		i++;
	}
}

int		main(void)
{
	int i;
	int i2;
	int i3;
	int i4;
	int i7;
	char c;
	char c2;
	char *s2;
	char *s4;

	i = 144;
	i2 = 21;
	i3 = 34;
	s4 = "test22";
	i7 = 84;
	s2 = "TEST";
	c = 'a';
	c2 = 'F';
	ft_printf("var c = %c\ni3 = %+d\ns2 = %s\ni7 = %07d\ns4 = %s\n", c, i3, s2, i7, s4);
}
