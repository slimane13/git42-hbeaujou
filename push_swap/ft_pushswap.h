/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 16:50:57 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/26 16:51:12 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft/includes/libft.h"

#define sa ft_switch(l_a)
#define sb ft_switch(l_b)
#define ss ft_bot_switch(l_a, l_b)
#define pa ft_to_first(l_a, l_b)
#define pb ft_to_first(l_b, l_a)
#define ra ft_rotate_begin(l_a)
#define rb ft_rotate_begin(l_b)
#define rr ft_both_rotate_begin(l_a, l_b)
#define rra ft_rotate_last(l_a)
#define rrb ft_rotate_last(l_b)
#define rrr ft_both_rotate_last(l_a, l_b)

void ft_switch(int *tab);
void ft_both_switch(int *tab, int *tab2);
void ft_to_first(int *tab, int *tab2);
void ft_rotate_begin(int *tab);
void ft_both_rotate_begin(int *tab, int *tab2);
void ft_rotate_last(int *tab);
void ft_both_rotate_last(int *tab, int *tab2);
void ft_avance(int *tab);
void ft_recule(int *tab);
void affiche(int *tab, int len);
void put_blanks(int *tab, int nb);
void ft_atoi_tab(int *l_a, char **tab, int len);

int ft_is_valid(int *tab);
