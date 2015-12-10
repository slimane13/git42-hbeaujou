/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:53:53 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/10 13:32:44 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <stdio.h>
# include <strings.h>
# include <unistd.h>
# include <fcntl.h>
# include "read.h"

int		*try_tetris_2(int *t1, int *t2, int passage, int target);
int		*try_tetris_2_special(int *t1, int *t2,
		int k, int passage, int target);
int		*try_tetris_2_2(int *t1, int *t2, int k, int passage, int target);
int		*tab_char_to_int(char *str);
int		*ft_strdup_int(int *s, int taille);
void	ft_strcpy_int(int *dest, int *src, int taille);
int		*ft_memalloc_int(size_t size);
int		keep_form(int *t1, int *spc, int taille);
int		**struct_to_tab(t_map *beg, char **tetri_list);
void	rewind_tetris(int *tab, int target);
int		*resitue(int *tab, int taille, int g_len_mx);
int		calc_larg(int *tab, int taille);
int		calc_haut(int *tab, int taille);
int		absc(int a, int b);
void	assign_spot(int *tab);
int		overlap_3(int *t1, int *t2, int taille);
int		is_valid(int *t1, int taille, int *spc);
int		check_pos_23(int pos, int *t1);
int		check_pos_32(int pos, int *t1);
int		*situe_point(char *str);
void	ft_cut_f2_special(int i2, int g_nbr_crt[26], int gt[2], int flag[26]);
void	cut_main(int *ite, char **tetri_list);
void	attrib_iter(void);
void	attrib_iter_first(void);
void	attrib_iter_second(void);
void	ft_cut_try_special(int varx[3], int passage, int *t1, int *t2);
void	define(void);
void	instance(int ite, char **tetri_list, char *str);
void	attrb_2(int *backtrack);
void	lance_boucle_14(int nbr, int flag[26], int g_nbr_crt[26]);
void	lance_boucle_59(int nbr, int flag[26], int g_nbr_crt[26]);
void	lance_boucle_14_2(int nbr, int flag[26], int g_nbr_crt[26]);
void	lance_boucle_59_2(int nbr, int flag[26], int g_nbr_crt[26]);
void	lance_boucle_14_3(int nbr, int flag[26], int g_nbr_crt[26]);
void	lance_boucle_59_3(int nbr, int flag[26], int g_nbr_crt[26]);
void	calc(int *clean, int *nbr, int i, int *t1, int *t2, int indice);
void	affiche(int *g_final);
void	affiche_special(int *g_final);
void	remp_blank(int *tab);
void	resolve(void);
void	assign_spot_special(int *tab, int *counter);
void	ft_cut_try_2_2(int vari[3], int passage, int *t1, int *t2);
void	choix_boucle(int nbr);
void	choix_boucle_tier1(int nbr, int flag[26], int g_nbr_crt[26]);
void	choix_boucle_tier2(int nbr, int flag[26], int g_nbr_crt[26]);
void	choix_boucle_tier3(int nbr, int flag[26], int g_nbr_crt[26]);

int		check1(int *t1);
int		check2(int *t1);
int		check3(int *t1);
int		check4(int *t1);
int		check5(int *t1);
int		check6(int *t1);
int		check7(int *t1);
int		check8(int *t1);

int		check1_32(int *t1);
int		check2_32(int *t1);
int		check3_32(int *t1);
int		check4_32(int *t1);
int		check5_32(int *t1);
int		check6_32(int *t1);
int		check7_32(int *t1);
int		check8_32(int *t1);

void	ft_boucle_f1_big(int flag[26], int g_nbr_crt[26]);
void	ft_boucle_f1_special(int flag[26], int g_nbr_crt[26]);
void	ft_boucle_f1_special_2(int flag[26], int g_nbr_crt[26]);
void	ft_boucle_f2_big(int flag[26], int g_nbr_crt[26]);
void	ft_boucle_f2_special(int flag[26], int g_nbr_crt[26]);
void	ft_boucle_f3_big(int flag[26], int g_nbr_crt[26]);
void	ft_boucle_f4_big(int flag[26], int g_nbr_crt[26]);
void	ft_boucle_f5_big(int flag[26], int g_nbr_crt[26]);
void	ft_boucle_f6_big(int flag[26], int g_nbr_crt[26]);
void	ft_boucle_f7_big(int flag[26], int g_nbr_crt[26]);
void	ft_boucle_f8_big(int flag[26], int g_nbr_crt[26]);
void	ft_boucle_f9_big(int flag[26], int g_nbr_crt[26]);
void	ft_boucle_f10_big(int flag[26], int g_nbr_crt[26]);
void	ft_boucle_f11_big(int flag[26], int g_nbr_crt[26]);
void	ft_boucle_f12_big(int flag[26], int g_nbr_crt[26]);
void	ft_boucle_f13_big(int flag[26], int g_nbr_crt[26]);
void	ft_boucle_f14_big(int flag[26], int g_nbr_crt[26]);
void	ft_boucle_f15_big(int flag[26], int g_nbr_crt[26]);
void	ft_boucle_f16_big(int flag[26], int g_nbr_crt[26]);
void	ft_boucle_f17_big(int flag[26], int g_nbr_crt[26]);
void	ft_boucle_f18_big(int flag[26], int g_nbr_crt[26]);
void	ft_boucle_f19_big(int flag[26], int g_nbr_crt[26]);
void	ft_boucle_f20_big(int flag[26], int g_nbr_crt[26]);
void	ft_boucle_f21_big(int flag[26], int g_nbr_crt[26]);
void	ft_boucle_f22_big(int flag[26], int g_nbr_crt[26]);
void	ft_boucle_f23_big(int flag[26], int g_nbr_crt[26]);
void	ft_boucle_f24_big(int flag[26], int g_nbr_crt[26]);
void	ft_boucle_f25_big(int flag[26], int g_nbr_crt[26]);
void	ft_boucle_f26_big(int flag[26], int g_nbr_crt[26]);

extern int *g_resolution;
extern int	*g_tampon;
extern int	*g_tmp_calc;
extern int	*g_final;
extern int	g_larg_max;
extern int g_haut_max;
extern int	g_t_l;
extern int	g_t_h;
extern int g_iter_max;
extern int g_abs_tmp;
extern int g_len_mx;
extern int	**g_points;
extern int **g_var;
extern int g_nbr_crt;
extern int g_nbr_tetri;
extern int g_test_max;
extern int g_trouve;
extern int *g_show_l;

extern int g_flag_try;

#endif
