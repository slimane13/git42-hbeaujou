/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:53:53 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/08 14:38:18 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <unistd.h>
#include <fcntl.h>
#include "read.h"

int		*try_tetris_2(int *t1, int *t2, int taille, int **spc, int k, int passage, int target);
int		*try_tetris_2_special(int *t1, int *t2, int taille, int **spc, int k, int passage, int target);
int		*try_tetris_2_2(int *t1, int *t2, int taille, int **spc, int k, int passage, int target);
int		*tab_char_to_int(char *str);
int		*ft_strdup_int(int *s, int taille);
void 	ft_strcpy_int(int *dest, int *src, int taille);
int 	*ft_memalloc_int(size_t size);
int		keepForm(int *t1, int *spc, int taille);
int		**struct_to_tab(t_map *beg, char **tetriList);
void	rewind_tetris(int *tab, int target);
int		*resitue(int *tab, int taille, int taille_max);
int		calc_larg(int *tab, int taille);
int		calc_haut(int *tab, int taille);
int		abs_minus(int a, int b);
void    assignSpot(int *tab);
int     overlap_3(int *t1, int *t2, int taille);
int     isValid(int *t1, int taille, int *spc);
void	affiche(int *final);
void	affiche_special(int *final);
void	remp_blank(int *tab);
void	choix_boucle(int nbr);
void	choix_boucle_tier1(int nbr, int flag[26], int nbrCourant[26]);
void	choix_boucle_tier2(int nbr, int flag[26], int nbrCourant[26]);
void	choix_boucle_tier3(int nbr, int flag[26], int nbrCourant[26]);

int check1(int *t1);
int check2(int *t1);
int check3(int *t1);
int check4(int *t1);
int check5(int *t1);
int check6(int *t1);
int check7(int *t1);
int check8(int *t1);

int check1_32(int *t1);
int check2_32(int *t1);
int check3_32(int *t1);
int check4_32(int *t1);
int check5_32(int *t1);
int check6_32(int *t1);
int check7_32(int *t1);
int check8_32(int *t1);

void ft_boucle_f1_big(int flag[26], int nbrCourant[26]);
void ft_boucle_f1_special(int flag[26], int nbrCourant[26]);
void ft_boucle_f2_big(int flag[26], int nbrCourant[26]);
void ft_boucle_f2_special(int flag[26], int nbrCourant[26]);
void ft_boucle_f3_big(int flag[26], int nbrCourant[26]);
void ft_boucle_f4_big(int flag[26], int nbrCourant[26]);
void ft_boucle_f5_big(int flag[26], int nbrCourant[26]);
void ft_boucle_f6_big(int flag[26], int nbrCourant[26]);
void ft_boucle_f7_big(int flag[26], int nbrCourant[26]);
void ft_boucle_f8_big(int flag[26], int nbrCourant[26]);
void ft_boucle_f9_big(int flag[26], int nbrCourant[26]);
void ft_boucle_f10_big(int flag[26], int nbrCourant[26]);
void ft_boucle_f11_big(int flag[26], int nbrCourant[26]);
void ft_boucle_f12_big(int flag[26], int nbrCourant[26]);
void ft_boucle_f13_big(int flag[26], int nbrCourant[26]);
void ft_boucle_f14_big(int flag[26], int nbrCourant[26]);
void ft_boucle_f15_big(int flag[26], int nbrCourant[26]);
void ft_boucle_f16_big(int flag[26], int nbrCourant[26]);
void ft_boucle_f17_big(int flag[26], int nbrCourant[26]);
void ft_boucle_f18_big(int flag[26], int nbrCourant[26]);
void ft_boucle_f19_big(int flag[26], int nbrCourant[26]);
void ft_boucle_f20_big(int flag[26], int nbrCourant[26]);
void ft_boucle_f21_big(int flag[26], int nbrCourant[26]);
void ft_boucle_f22_big(int flag[26], int nbrCourant[26]);
void ft_boucle_f23_big(int flag[26], int nbrCourant[26]);
void ft_boucle_f24_big(int flag[26], int nbrCourant[26]);
void ft_boucle_f25_big(int flag[26], int nbrCourant[26]);
void ft_boucle_f26_big(int flag[26], int nbrCourant[26]);

extern int *resolution;
extern int	*tampon;
extern int	*tmpCalc;
extern int	*final;
extern int	larg_max;
extern int haut_max;
extern int	test_larg;
extern int	test_haut;
extern int iter_max;
extern int absTmp;
extern int taille_max;
extern int	**points;
extern int **var;
extern int nbrCourant;
extern int nbrTetri;
extern int test_max;
extern int trouve;
extern int *affichageLettre;

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
