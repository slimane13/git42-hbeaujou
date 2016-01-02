/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 16:50:57 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/02 13:18:23 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP_H
# define FT_PUSHSWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "libft/includes/libft.h"

# define SA ft_switch(l_a)
# define SB ft_switch(l_b)
# define SS ft_both_switch(l_a, l_b)
# define PA ft_to_first(l_a, l_b)
# define PB ft_to_first(l_b, l_a)
# define RA ft_rotate_begin(l_a)
# define RB ft_rotate_begin(l_b)
# define RR ft_both_rotate_begin(l_a, l_b)
# define RRA ft_rotate_last(l_a)
# define RRB ft_rotate_last(l_b)
# define RRR ft_both_rotate_last(l_a, l_b)

void 	ft_switch(int *tab);
void 	ft_both_switch(int *tab, int *tab2);
void 	ft_to_first(int *tab, int *tab2);
void 	ft_rotate_begin(int *tab);
void 	ft_both_rotate_begin(int *tab, int *tab2);
void 	ft_rotate_last(int *tab);
void 	ft_both_rotate_last(int *tab, int *tab2);
void 	ft_avance(int *tab);
void 	ft_recule(int *tab);
void	resolve_test(int *l_a, int *l_b, int max);
void 	affiche(int *tab, int len);
void 	put_blanks(int *tab, int nb);
void	do_tests(int *tab, int *l_a, int *l_b);
void	apply_test(int ret, int *l_a, int *l_b);
void 	ft_atoi_tab(int *l_a, char **tab, int len);

int		test_ra(int *l_a, int *l_b);
int		test_rra(int *l_a, int *l_b);
int		test_sa(int *l_a, int *l_b);
int		test_rb(int *l_a, int *l_b);
int		test_rrb(int *l_a, int *l_b);
int		test_sb(int *l_a, int *l_b);
int		test_ss(int *l_a, int *l_b);
int		test_rr(int *l_a, int *l_b);
int		test_rrr(int *l_a, int *l_b);
int		attrib_tests(int *tab);
int		attrib_tests(int *tab);
int		tab_len(int *tab);
int		find_min_iter(int *tab);
int		find_min(int *tab);
int		find_min_2(int *tab, int min);
int		find_max(int *tab);
int		nb_classed(int *tab);
int 	ft_is_valid(int *tab);

#endif
