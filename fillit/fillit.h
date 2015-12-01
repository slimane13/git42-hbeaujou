/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:53:53 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/01 17:52:54 by hbeaujou         ###   ########.fr       */
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
int	*ft_intdup(int *src, int len); //USELESS
void	boucle_test(int nbrTetri, int iterMax, int nbrCourant, int *largMax, // USELESS
		int *hautMax, int *absTmp, int *tampon, int tailleMax, int **var, int **final, int **points, int *clean);

void ft_boucle_f1(void);
void ft_boucle_f2(void);
void ft_boucle_f3(void);
void ft_boucle_f4(void);
void ft_boucle_f5(void);

extern int *clean;
extern int	*tampon;
extern int	*tmpCalc;
extern int	*final;
extern int	largMax;
extern int hautMax;
extern int	testLarg;
extern int	testHaut;
extern int iterMax;
extern int absTmp;
extern int tailleMax;
extern int	**points;
extern int **var;
extern int nbrCourant;
extern int flagF1;
extern int flagF2;

#endif
