/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 13:34:50 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/17 19:15:42 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_printf.h"

int		retour;

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
			if ((str[count[0]][ft_strlen(str[count[0]]) - 1] == 'd' ||
					str[count[0]][ft_strlen(str[count[0]]) - 1] == 'i') &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] != 'h')
			{
				if (str[count[0]][ft_strlen(str[count[0]]) - 2] == '*')
				{
					var[count[2]]->stars = va_arg(liste, int);
					var[count[2]]->entier = va_arg(liste, int);
					attrib_d(str, var, count);
				}
				else
				{
					var[count[2]]->entier = va_arg(liste, int);
					attrib_d(str, var, count);
				}
			}
			else if	(str[count[0]][ft_strlen(str[count[0]]) - 1] == 'u' ||
					str[count[0]][ft_strlen(str[count[0]]) - 1] == 'U')
			{
				if (str[count[0]][ft_strlen(str[count[0]]) - 2] == '*')
				{
					var[count[2]]->stars = va_arg(liste, int);
					var[count[2]]->u_entier = (unsigned int)va_arg(liste, int);
					attrib_u(str, var, count);
				}
				else
				{
					var[count[2]]->u_entier = (unsigned int)va_arg(liste, int);
					attrib_u(str, var, count);
				}
			}
			else if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'c' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] != 'h')  /////// A DEGAGER
			{
				if (str[count[0]][ft_strlen(str[count[0]]) - 2] == '*')
				{
					var[count[2]]->stars = va_arg(liste, int);
					var[count[2]]->string = ft_itoa(va_arg(liste, int));
					attrib_c(str, var, count);
				}
				else
				{
					var[count[2]]->string = ft_itoa(va_arg(liste, int));
					attrib_c(str, var, count);
				}
			}
			else if ((str[count[0]][ft_strlen(str[count[0]]) - 1] == 's' ||
					str[count[0]][ft_strlen(str[count[0]]) - 1] == 'S') &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] != 'h') /////// A DEGAGER
			{
				var[count[2]]->string = va_arg(liste, char *);
				attrib_s(str, var, count);
			}
			else if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'p' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] != 'h')
			{
				var[count[2]]->entier = va_arg(liste, int);
				attrib_p(str, var, count);
			}
			else if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'x' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] != 'h')
			{
				if (str[count[0]][ft_strlen(str[count[0]]) - 2] == '*')
				{
					var[count[2]]->stars = va_arg(liste, int);
					var[count[2]]->entier = va_arg(liste, int);
					var[count[2]]->u_short = (unsigned short)var[count[2]]->entier;
					attrib_x(str, var, count);
				}
				else
				{
					var[count[2]]->entier = va_arg(liste, int);
					attrib_x(str, var, count);
				}
			}
			else if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'X' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] != 'h')
			{
				if (str[count[0]][ft_strlen(str[count[0]]) - 2] == '*')
				{
					var[count[2]]->stars = va_arg(liste, int);
					var[count[2]]->entier = va_arg(liste, int);
					var[count[2]]->u_short = (unsigned short)var[count[2]]->entier;
					attrib_x_maj(str, var, count);
				}
				else
				{
					var[count[2]]->entier = va_arg(liste, int);
					attrib_x_maj(str, var, count);
				}
			}
			else if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'o' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] != 'h')
			{
				if (str[count[0]][ft_strlen(str[count[0]]) - 2] == '*')
				{
					var[count[2]]->stars = va_arg(liste, int);
					var[count[2]]->entier = va_arg(liste, int);
					var[count[2]]->u_short = (unsigned short)var[count[2]]->entier;
					attrib_o(str, var, count);
				}
				else
				{
					var[count[2]]->entier = va_arg(liste, int);
					var[count[2]]->u_short = (unsigned short)var[count[2]]->entier;
					attrib_o(str, var, count);
				}
			}
			else if (str[count[0]][ft_strlen(str[count[0]]) - 2] == 'h' &&
				str[count[0]][ft_strlen(str[count[0]]) - 3] != 'h')
			{
				var[count[2]]->entier = va_arg(liste, int);
				attrib_h_h(str, var, count);
			}
			else if (str[count[0]][ft_strlen(str[count[0]]) - 2] == 'h' &&
				str[count[0]][ft_strlen(str[count[0]]) - 3] == 'h')
			{
				var[count[2]]->entier = va_arg(liste, int);
				attrib_h_h(str, var, count);
			}
			else if (str[count[0]][ft_strlen(str[count[0]]) - 2] == 'l' &&
				str[count[0]][ft_strlen(str[count[0]]) - 3] != 'l')
			{
				var[count[2]]->entier = va_arg(liste, int);
				attrib_h_h(str, var, count);
			}
			else if (str[count[0]][ft_strlen(str[count[0]]) - 2] == 'l' &&
				str[count[0]][ft_strlen(str[count[0]]) - 3] == 'l')
			{
				var[count[2]]->entier = va_arg(liste, int);
				attrib_h_h(str, var, count);
			}
			else if (str[count[0]][ft_strlen(str[count[0]]) - 2] == 'j')
			{
				var[count[2]]->entier = va_arg(liste, int);
				attrib_h_h(str, var, count);
			}
			else if (str[count[0]][ft_strlen(str[count[0]]) - 2] == 'z')
			{
				var[count[2]]->entier = va_arg(liste, int);
				attrib_h_h(str, var, count);
			}
		}
		count[0]++;
	}
}

int		ft_printf(char *format ,...)
{
	va_list		liste;
	char		**str_split;
	char		*new_str;
	t_var		**var;
	int			nbr_var_percent;
	int			size;
	int			i;
	int			*tab;

	retour = 0;
	size = 0;
	i = 0;
	
	size = ft_strlen(format);
	nbr_var_percent = run_var(format, '%');
	size++;

	tab = (int *)malloc(sizeof(int) * 20);
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(format) + nbr_var_percent * 4));
	var = (t_var **)malloc(sizeof(t_var) * nbr_var_percent);
	while (i < nbr_var_percent)
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
		retour += ft_strlen(str_split[i]);
		ft_putstr(str_split[i]);
		i++;
	}
	return (retour);
}

int		main(void)
{
	int i;
	int i2;
	int i3;
	int i4;
	int i7;
	int *sO;
	long long c5;
	char c;
	char c2;
	char *s1;
	char *s2;
	char *s4;
	char *s7;

	i = -144;
	i2 = -40;
	i3 = 34;
	s4 = "test22";
	i7 = 69;
	s1 = "mdrk";
	s2 = "TEST";
	sO = &i3;
	c = 'a';
	c5 = 'Z';
	c2 = 'F';
//	ft_printf("s1 = %.s s2 = %.s\n\n", "bonjour", "toto");
//	ft_printf("i3 = %*d\n&i7 = %-3p\ni7 = %9.6d\ns2 = %.s\ni2 = %o\nc5 = %-.3ld\n", 10, i3, &i7, -i7, s2, i2, c5);
//	printf("i2 offi = %o\n", i2);
//	ft_printf("i = %u\n", i);
//	printf("i offi = %u\n", i);
//	ft_printf("%s\n", "LOLOL");
//	printf("\ns = %ls\n", L"LOLOL");

//	printf("%o\n%o\n%o\n%o\n%o\n", 1, 100, 999, 42, 999988888);
//	printf("\n");
//	ft_printf("%o\n%o\n%o\n%o\n%o\n", 1, 100, 999, 42, 999988888);
	printf("s: %s, p: %p, d:%d", "a string", &s2, 42);
	printf("\n");
	ft_printf("s: %s, p: %p, d:%d", "a string", &s2, 42);
	printf("\n");
//	printf("% u", 9999);
//	printf("\n");
//	ft_printf("% u", 9999);
//	printf("\n");
	printf("{%*c}", 0, 0);
	printf("\n");
	ft_printf("{%*c}", 0, 0);
	printf("\n");
//	ft_printf("{%03c}", 0);
}
