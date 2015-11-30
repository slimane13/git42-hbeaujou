/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:53:53 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/11/30 17:00:19 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

//#include "libft.h" // .a ?
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <unistd.h>
#include <fcntl.h>
#include "read.h"

int	*try_tetris(int *t1, int *t2, int taille, int **spc, int k);
int	*try_tetris_2(int *t1, int *t2, int taille, int **spc, int k, int passage, int target);
int	*tab_char_to_int(char *str);
int	*ft_strdup_int(int *s);
int *ft_strcpy_int(int *dest, int *src);
int	*ft_memalloc_int(size_t size);
int	keepForm(int *t1, int *spc, int taille);
int	**struct_to_tab(t_map *beg);
void	rewind_tetris(int *tab, int target);
int	*resitue(int *tab, int taille, int tailleMax);
int	calc_larg(int *tab, int taille);
int	calc_haut(int *tab, int taille);
void	affiche(int *final);
int	abs_minus(int a, int b);
int	*ft_intdup(int *src, int len);
void	boucle_test(int nbrTetri, int iterMax, int nbrCourant, int *largMax,
		int *hautMax, int *absTmp, int *tampon, int tailleMax, int **var, int **final, int **points, int *clean);

#endif
