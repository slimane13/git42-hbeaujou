/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 13:35:14 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/25 14:01:01 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	unsigned char	mem[2048];
	unsigned char	*ptr;
	int				i;
	int				idem;
	int				trouve;

	trouve = 0;
	idem = 0;
	i = 0;
	ptr = mem;
	if (argc != 2)
	{
		printf("\n"); // A FAIRE AVEC PUTCHAR
		return (0);
	}
	while (argv[1][i])
	{
		if (argv[1][i] == '>')
			ptr++;
		else if (argv[1][i] == '<')
			ptr--;
		else if (argv[1][i] == '+')
			*ptr = *ptr + 1;
		else if (argv[1][i] == '-')
			*ptr = *ptr - 1;
		else if (argv[1][i] == '.')
			printf("%c", *ptr); // A FAIRE AVEC PUTCHAR
		else if (argv[1][i] == '[')
		{
			if (*ptr == 0)
			{
				i++;
				while (trouve != 1)
				{
					if (argv[1][i] == ']' && idem == 0)
						trouve = 1;
					else if (argv[1][i] == '[')
						idem++;
					else if (argv[1][i] == ']' && idem != 0)
						idem--;
					i++;
				}
			}
			trouve = 0;
		}
		else if (argv[1][i] == ']')
		{
			if (*ptr != 0)
			{
				i--;
				while (trouve != 1)
				{
					if (argv[1][i] == '[' && idem == 0)
						trouve = 1;
					else if (argv[1][i] == ']')
						idem++;
					else if (argv[1][i] == '[' && idem != 0)
						idem--;
					i--;
				}
			}
		}
		else
			;
		i++;
	}
	return (0);
}
