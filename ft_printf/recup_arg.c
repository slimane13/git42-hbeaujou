/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 11:51:58 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/11 12:37:51 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

int ft_printchar(char **str, int c)
{
	int putchar(int c);
	
	if (str)
	{
		**str = c;
		++(*str);

	}
	else
		(void)putchar(c);
	return (0);
}

int	ft_prints(char **out, const char *string, int larg, int len)
{
	return (0);
}

int	ft_printi(char **out, int i, int n, int sg, int larg, int len, int letbase)
{
	return (0);
}

int	ft_print(char **out, const char *format, va_list args)
{
	int larg;
	int len;

	while (format != 0)
	{
		if (*format == '%')
		{
			++format;
			if (*format == '\0')
				return (0);
			else if(*format == '%')
				return (0);
			else if (*format == '-')
			{
				pad = 1;
				++format;
			}
			while (*format <= '9' && *format >= '0')
			{
				larg = larg * 10 + *format - '0';
				format++;
			}
			if (*format == 's')
			{
				//
			}
			else if (*format == 'S')
			{
				//
			}
			else if (*format == 'p')
			{
				//
			}
			else if (*format == 'd')
			{
				printf("AAAAAA\n");
				//
			}
			else if (*format == 'D')
			{
				//
			}
			else if (*format == 'i')
			{
				//
			}
			else if (*format == 'o')
			{
				//
			}
			else if (*format == 'O')
			{
				//
			}
			else if (*format == 'u')
			{
				//
			}
			else if (*format == 'U')
			{
				//
			}
			else if (*format == 'x')
			{
				//
			}
			else if (*format == 'X')
			{
				//
			}
			else if (*format == 'c')
			{
				//
			}
			else if (*format == 'C')
			{
				//
			}
		}
		else
		{
			ft_princhar(out, *format);
		}
		format++;
	}
	va_end(args);
}

int	ft_printf(char *out, const char *format)
{
	va_list args;

	va_start(args, format);
	return (ft_print(&out, format, args));
}

int main(void)
{
	int a;
	char buf[30];

	a = 3;
	ft_printf("%d", buf);
	return (0);
}
