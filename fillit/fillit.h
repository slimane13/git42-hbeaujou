/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:53:53 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/03 12:20:09 by hbeaujou         ###   ########.fr       */
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
int	*ft_strdup_int(int *s, int taille);
void ft_strcpy_int(int *dest, int *src, int taille);
int *ft_memalloc_int(size_t size);
int	keepForm(int *t1, int *spc, int taille);
int	**struct_to_tab(t_map *beg);
void	rewind_tetris(int *tab, int target);
int	*resitue(int *tab, int taille, int tailleMax);
int	calc_larg(int *tab, int taille);
int	calc_haut(int *tab, int taille);
int	abs_minus(int a, int b);
void	affiche(int *final);
void remp_blank(int *tab);
void	choix_boucle(int nbr);
void	choix_boucle_tier1(int nbr);
void	choix_boucle_tier2(int nbr);
void	choix_boucle_tier3(int nbr);

void ft_boucle_f1(void);
void ft_boucle_f2(void);
void ft_boucle_f3(void);
void ft_boucle_f4(void);
void ft_boucle_f5(void);
void ft_boucle_f6(void);
void ft_boucle_f7(void);
void ft_boucle_f8(void);
void ft_boucle_f9(void);
void ft_boucle_f10(void);
void ft_boucle_f11(void);
void ft_boucle_f12(void);
void ft_boucle_f13(void);
void ft_boucle_f14(void);
void ft_boucle_f15(void);
void ft_boucle_f16(void);
void ft_boucle_f17(void);
void ft_boucle_f18(void);
void ft_boucle_f19(void);
void ft_boucle_f20(void);
void ft_boucle_f21(void);
void ft_boucle_f22(void);
void ft_boucle_f23(void);
void ft_boucle_f24(void);
void ft_boucle_f25(void);
void ft_boucle_f26(void);

extern int *resolution;
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
extern int nbrTetri;

extern int *clean;
extern int *clean2;
extern int *clean3;
extern int *clean4;
extern int *clean5;
extern int *clean6;
extern int *clean7;
extern int *clean8;
extern int *clean9;
extern int *clean10;
extern int *clean11;
extern int *clean12;
extern int *clean13;
extern int *clean14;
extern int *clean15;
extern int *clean16;
extern int *clean17;
extern int *clean18;
extern int *clean19;
extern int *clean20;
extern int *clean21;
extern int *clean22;
extern int *clean23;
extern int *clean24;
extern int *clean25;
extern int *clean26;

extern int flagTRY;
extern int flagF1;
extern int flagF2;
extern int flagF3;
extern int flagF4;
extern int flagF5;
extern int flagF6;
extern int flagF7;
extern int flagF8;
extern int flagF9;
extern int flagF10;
extern int flagF11;
extern int flagF12;
extern int flagF13;
extern int flagF14;
extern int flagF15;
extern int flagF16;
extern int flagF17;
extern int flagF18;
extern int flagF19;
extern int flagF20;
extern int flagF21;
extern int flagF22;
extern int flagF23;
extern int flagF24;
extern int flagF25;
extern int flagF26;

extern int i2;
extern int i3;
extern int i4;
extern int i5;
extern int i6;
extern int i7;
extern int i8;
extern int i9;
extern int i10;
extern int i11;
extern int i12;
extern int i13;
extern int i14;
extern int i15;
extern int i16;
extern int i17;
extern int i18;
extern int i19;
extern int i20;
extern int i21;
extern int i22;
extern int i23;
extern int i24;
extern int i25;
extern int i26;

#endif
