/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 11:10:11 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/03 16:15:56 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP_H
# define FT_PUSHSWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct		s_stack
{
	int				nb;
	int				nb_elem;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

extern int			g_coups;

t_stack				*ft_creat_element(int nb);
int					find_min(t_stack *l_a);
int					push_b(t_stack **l_a, t_stack **l_b);
int					push_a(t_stack **l_a, t_stack **l_b);
int					ft_is_sort(t_stack *x);
int					initialize(t_stack **l_a, t_stack **l_b);
int					ft_list_back(t_stack **stack, int nb);
int					ft_list_front(t_stack **stack, int nb);
int					ft_check_1(int ac, t_stack *l_a);
void				ft_cut_1(t_stack *l_a);
void				resolve(t_stack *l_a, t_stack *l_b);
void				affiche(t_stack *l_a);
void				resolve_rotate(t_stack *l_a);
void				resolve_stack_b(t_stack *l_a, t_stack *l_b);
void				swap(t_stack **stack);
void				rotate(t_stack **stack);
void				rev_rotate(t_stack **stack);
void				ft_check_3(char **av, int ac, t_stack **l_a);
void				ft_check_2(char **av, int ac,
		int *tab_nb, t_stack **l_a);

#endif
