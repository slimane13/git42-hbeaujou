/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 16:49:32 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/02 13:18:43 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int ft_is_valid(int *tab)
{
    int i;

    i = 0;
    while(tab[i + 1] != 0 && tab[i + 1] != '\0')
    {
        if (tab[i] > tab[i + 1])
            return (0);
		i++;
    }
    return (1);
}

void affiche(int *tab, int len)
{
    int i;

    i = 0;
    printf("\n");
    while(i < len)
    {
        printf("%d ", tab[i]);
        i++;
    }
}

void put_blanks(int *tab, int nb)
{
    int i;

    i = 0;
    while(i < nb)
    {
        tab[i] = 0;
        i++;
    }
}

void resolve(int *l_a, int *l_b, int max)
{
    while(!ft_is_valid(l_a))
    {
        if (l_a[0] > l_a[1] && l_a[0] != max)
        {
            SA;
            printf("sa ");
        }
        RA;
        printf("ra ");
    }
}
// A METTRE DANS LA LIBFTPRINTF avec _spec
void ft_atoi_tab(int *l_a, char **tab, int len)
{
    int i;
    int j;

    i = 1;
    j = 0;
    while(i < len)
    {
        l_a[j] = ft_atoi(tab[i]);
        i++;
        j++;
    }
    l_a[j + 1] = 0;
    l_a[j] = 0;
}

int main(int argc, char **argv)
{
    int nbr;
    int *l_a;
    int *l_b;

    nbr = argc + 1;
    l_a = (int *)malloc(sizeof(int) * nbr);
    l_b = (int *)malloc(sizeof(int) * nbr);

    ft_atoi_tab(l_a, argv, nbr - 1);
    put_blanks(l_b, nbr);
    affiche(l_a, nbr - 2);
	printf("\n");
    resolve_test(l_a, l_b, find_max(l_a));
    affiche(l_a, nbr - 2);

    return (0);
}
