/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computorv1.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 09:05:19 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/08/17 17:25:29 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdodo.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct s_elem		t_elem;
typedef struct s_equ		t_equ;
typedef struct s_solve		t_solve;

struct					s_equ
{
	t_elem	*content;
	t_equ	*next;
};

struct					s_elem
{
	double	value;
	int		puissance;
	t_elem	*next;
};

struct					s_solve
{
	double	value;
	t_solve	*next;
};

extern int	g_some;

t_elem					*new_elem(double valu, int puissanc);
t_equ					*new_equ(t_elem *conten);
t_solve					*new_solve(double valu);

char					*deblank(char* input);
void					ft_lstaddend_solve(t_solve **alst, t_solve *new_r);
void					ft_lstaddend_elem(t_elem **alst, t_elem *new_r);
void					ft_lstaddend_equ(t_equ **alst, t_equ *new_r);
