/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 17:46:52 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/01 17:31:37 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <stdarg.h>
# include <limits.h>

typedef struct			s_var
{
	intmax_t			im_t;
	int					entier;
	int					stars;
	unsigned char		u_carac;
	unsigned int		u_entier;
	unsigned short		u_short;
	unsigned long		u_long;
	unsigned long long	u_l_long;
	long				v_long;
	long long			v_l_long;
	short				v_short;
	char				carac;
	char				*string;
	wchar_t				*w_string;
	wint_t				w_entier;
}						t_var;

typedef struct			s_cut
{
	int					nbr;
	int					nbrlen;
	int					s_nbr;
	int					spec;
	int					l;
	int					flag;
	int					flag_save;
	int					k;
	int					p;
	int					diff;
	int					check;
	int					c_d;
	int					neg;
	int					compteur;
	int					i;
	int					str_len;
	char				c;
	char				g;
	char				last;
	char				z;
	char				m;
	char				*str_2;
}						t_cut;

extern int				g_tt[3];
extern int				g_rajout;
extern int				g_char_nul;
extern int				g_s_maj;

int						utf8encode(char *buf, int codepoint);
int						is_ascii_code_point(int val);
int						check_conver(char *format, int var[3]);
int						check_flag(char **str, int count[3], int *nbr, char *c);
int						check_flag_number(char **str,
		int count[3], int *nbr, char *c);
int						is_indice(int nb, int *tab);
int						run_var(char *str, char c);
int						ft_wtomb(char *s, wchar_t wchar);

int						ft_printf(char *format, ...);

void					ft_cut_init_erreur(t_cut *t_v,
		char **str, int count[3]);
void					ft_cut_init_erreur2(t_cut *t_v,
		char **str, int count[3]);
void					ft_cut_flag_erreur1(t_cut *t_v,
		char **str, int count[3]);
void					ft_cut_flag_erreur2(t_cut *t_v,
		char **str, int count[3]);
void					ft_cut_flag_erreur2_1(t_cut *t_v,
		char **str, int count[3]);

void					attrib_erreur_conv_spec(char **str, int count[3]);
void					ft_c_c_f_erreur2(t_cut *t_v, char **str, int count[3]);

void					ft_c_c_init_d(t_cut *t_v, t_var **var, char **str,
		int count[3]);
void					ft_c_c_flag_d3(t_cut *t_v, char **str, int count[3]);
void					ft_c_c_flag_o1(t_cut *t_v, char **str, int count[3]);
void					ft_c_c_flag_o12(t_cut *t_v, char **str, int count[3]);
void					ft_c_c_flag_s2(t_cut *t_v, char **str, int count[3]);
void					ft_c_c_flag_x1(t_cut *t_v, char **str,
		int count[3], int *b);
void					ft_c_c_flag_x12(t_cut *t_v, char **str, int count[3]);

void					ft_cut_init_o_z(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_o1_z(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_o2_z(t_cut *t_v, char **str, int count[3]);
void					ft_cut_flag_o2_1z(t_cut *t_v, char **str, int count[3]);
void					ft_cut_flag_o2_2z(t_cut *t_v, char **str, int count[3]);

void					ft_cut_init_u_z(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_u1_z(t_cut *t_v, char **str, int count[3]);
void					ft_cut_flag_u2_z(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_u3_z(t_cut *t_v, char **str, int count[3]);
void					ft_cut_flag_u3_1z(t_cut *t_v, char **str, int count[3]);
void					ft_cut_flag_u3_2z(t_cut *t_v, char **str, int count[3]);

void					ft_cut_init_d_z(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_d1_z(t_cut *t_v, char **str, int count[3]);
void					ft_cut_flag_d2_z(t_cut *t_v, char **str, int count[3]);
void					ft_cut_flag_d3_z(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_d4_z(t_cut *t_v, char **str, int count[3]);
void					ft_cut_flag_d4_1z(t_cut *t_v, char **str, int count[3]);
void					ft_cut_flag_d4_2z(t_cut *t_v, char **str, int count[3]);

void					ft_cut_init_o_j(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_o1_j(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_o2_j(t_cut *t_v, char **str, int count[3]);
void					ft_cut_flag_o2_1j(t_cut *t_v, char **str, int count[3]);
void					ft_cut_flag_o2_2j(t_cut *t_v, char **str, int count[3]);

void					ft_cut_init_u_j(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_u1_j(t_cut *t_v, char **str, int count[3]);
void					ft_cut_flag_u2_j(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_u3_j(t_cut *t_v, char **str, int count[3]);
void					ft_cut_flag_u3_1j(t_cut *t_v, char **str, int count[3]);
void					ft_cut_flag_u3_2j(t_cut *t_v, char **str, int count[3]);

void					ft_cut_init_s_maj(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_init_s2_maj(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_s1_maj(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_s2_maj(t_cut *t_v,
		char **str, int count[3]);
void					ft_cut_flag_s3_maj(t_cut *t_v,
		char **str, int count[3]);
void					ft_cut_flag_s4_maj(t_cut *t_v,
		char **str, int count[3]);
void					ft_cut_flag_s5_maj(t_cut *t_v,
		char **str, int count[3]);
void					ft_cut_flag_s6_maj(t_cut *t_v,
		char **str, int count[3]);

void					ft_cut_init_d_j(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_d1_j(t_cut *t_v,
		char **str, int count[3]);
void					ft_cut_flag_d2_j(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_d3_j(t_cut *t_v, char **str, int count[3]);
void					ft_cut_flag_d3_1j(t_cut *t_v, char **str, int count[3]);
void					ft_cut_flag_d3_2j(t_cut *t_v, char **str, int count[3]);
void					ft_cut_flag_d4_j(t_cut *t_v, char **str, int count[3]);

void					ft_cut_init_x_mchr(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_x1_mchr(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_x2_mchr(t_cut *t_v, char **str,
		int count[3]);
void					ft_cut_flag_x2_1mchr(t_cut *t_v, char **str,
		int count[3]);
void					ft_cut_flag_x2_2mchr(t_cut *t_v, char **str,
		int count[3]);

void					ft_cut_init_x_char(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_x1_char(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_x2_char(t_cut *t_v, char **str,
		int count[3]);
void					ft_cut_flag_x2_1char(t_cut *t_v, char **str,
		int count[3]);
void					ft_cut_flag_x2_2char(t_cut *t_v, char **str,
		int count[3]);

void					ft_cut_init_o_char(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_o1_char(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_o2_char(t_cut *t_v, char **str,
		int count[3]);
void					ft_cut_flag_o2_1char(t_cut *t_v, char **str,
		int count[3]);
void					ft_cut_flag_o2_2char(t_cut *t_v, char **str,
		int count[3]);

void					ft_cut_init_u_char(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_u1_char(t_cut *t_v,
		char **str, int count[3]);
void					ft_cut_flag_u2_char(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_u3_char(t_cut *t_v,
		char **str, int count[3]);
void					ft_cut_flag_u3_1char(t_cut *t_v,
		char **str, int count[3]);
void					ft_cut_flag_u3_2char(t_cut *t_v,
		char **str, int count[3]);

void					ft_cut_init_d_char(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_d1_char(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_d2_char(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_d3_char(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_d3_1char(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_d4_char(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_d4_1char(t_cut *t_v, char **str,
		int count[3]);
void					ft_cut_flag_d4_2char(t_cut *t_v, t_var **var,
		char **str, int count[3]);

void					ft_cut_init_x_mshrt(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_x1_mshrt(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_x2_mshrt(t_cut *t_v, char **str,
		int count[3]);
void					ft_cut_flag_x2_1mshrt(t_cut *t_v, char **str,
		int count[3]);
void					ft_cut_flag_x2_2mshrt(t_cut *t_v, char **str,
		int count[3]);

void					ft_cut_init_x_short(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_x1_short(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_x2_short(t_cut *t_v, char **str,
		int count[3]);
void					ft_cut_flag_x2_1short(t_cut *t_v, char **str,
		int count[3]);
void					ft_cut_flag_x2_2short(t_cut *t_v, char **str,
		int count[3]);

void					ft_cut_init_d_ll(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_d1_ll(t_cut *t_v, char **str, int count[3]);
void					ft_cut_flag_d2_ll(t_cut *t_v, char **str, int count[3]);
void					ft_cut_flag_d3_ll(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_d3_1ll(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_d4_ll(t_cut *t_v, char **str, int count[3]);
void					ft_cut_flag_d4_1ll(t_cut *t_v, char **str,
		int count[3]);
void					ft_cut_flag_d4_2ll(t_cut *t_v, char **str,
		int count[3]);

void					ft_cut_init_u_llong(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_u1_llong(t_cut *t_v, char **str,
		int count[3]);
void					ft_cut_flag_u2_llong(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_u2_1llong(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_u3_llong(t_cut *t_v, char **str,
		int count[3]);
void					ft_cut_flag_u3_1llong(t_cut *t_v, char **str,
		int count[3]);
void					ft_cut_flag_u3_2llong(t_cut *t_v, char **str,
		int count[3]);

void					ft_cut_init_o_short(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_o1_short(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_o2_short(t_cut *t_v, char **str,
		int count[3]);
void					ft_cut_flag_o2_1short(t_cut *t_v, char **str,
		int count[3]);
void					ft_cut_flag_o2_2short(t_cut *t_v, char **str,
		int count[3]);

void					ft_cut_init_u_short(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_u1_short(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_u2_short(t_cut *t_v, char **str,
		int count[3]);
void					ft_cut_flag_u2_1short(t_cut *t_v, char **str,
		int count[3]);
void					ft_cut_flag_u2_2short(t_cut *t_v, char **str,
		int count[3]);

void					ft_cut_init_d_short(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_d1_short(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_d1_1short(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_d2_short(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_d3_short(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_d4_short(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_d4_1short(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_d4_2short(t_cut *t_v, char **str,
		int count[3]);

void					ft_cut_init_u_maj(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_u1_maj(t_cut *t_v, char **str,
		int count[3]);
void					ft_cut_flag_u2_maj(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_u3_maj(t_cut *t_v, char **str,
		int count[3]);
void					ft_cut_flag_u3_1maj(t_cut *t_v, char **str,
		int count[3]);
void					ft_cut_flag_u3_2maj(t_cut *t_v, char **str,
		int count[3]);

void					ft_cut_init_d_maj(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_d1_maj(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_d1_1maj(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_d2_maj(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_d3_maj(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_d4_maj(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_d4_1maj(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_d4_2maj(t_cut *t_v,
		char **str, int count[3]);

void					ft_cut_init_o_maj(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_o1_maj(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_o2_maj(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_o2_1maj(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_o3_maj(t_cut *t_v, char **str,
		int count[3]);
void					ft_cut_flag_o3_1maj(t_cut *t_v, char **str,
		int count[3]);
void					ft_cut_flag_o3_2maj(t_cut *t_v, char **str,
		int count[3]);
void					ft_cut_flag_o4_maj(t_cut *t_v, char **str,
		int count[3]);

void					ft_cut_init_u(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_u1(t_cut *t_v, char **str, int count[3]);
void					ft_cut_flag_u2(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_u3(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_u3_1(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_u4(t_cut *t_v, char **str, int count[3]);
void					ft_cut_flag_u4_1(t_cut *t_v, char **str, int count[3]);
void					ft_cut_flag_u4_2(t_cut *t_v, char **str, int count[3]);

void					ft_cut_init_c_maj(t_cut *t_v, t_var **var, char **str,
		int count[3]);
void					ft_cut_flag_c1_maj(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_c2_maj(t_cut *t_v, char **str,
		int count[3]);

void					ft_cut_init_o(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_o1(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_o2(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_o3(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_o3_1(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_o4(t_cut *t_v, char **str, int count[3]);
void					ft_cut_flag_o4_1(t_cut *t_v, char **str, int count[3]);
void					ft_cut_flag_o4_2(t_cut *t_v, char **str, int count[3]);

void					ft_cut_init_x_maj(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_x1_maj(t_var **var, char **str,
		int count[3]);
void					ft_cut_flag_x2_maj(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_x3_maj(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_x3_1maj(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_x4_maj(t_cut *t_v,
		char **str, int count[3]);
void					ft_cut_flag_x4_1maj(t_cut *t_v,
		char **str, int count[3]);
void					ft_cut_flag_x4_2maj(t_cut *t_v,
		char **str, int count[3]);

void					ft_cut_init_x_l(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_x1_l(t_cut *t_v, t_var **var,
		char **str, int count[3]);

void					ft_cut_init_x_lmaj(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_x1_lmaj(t_cut *t_v, t_var **var,
		char **str, int count[3]);

void					ft_cut_init_x(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_x1(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_x2(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_x3(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_x3_1(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_x4(t_cut *t_v, char **str, int count[3]);
void					ft_cut_flag_x4_1(t_cut *t_v, char **str, int count[3]);
void					ft_cut_flag_x4_2(t_cut *t_v, char **str, int count[3]);

void					ft_cut_init_p(t_cut *t_v, char **str, int count[3]);
void					ft_cut_flag_p1(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_p1_1(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_p1_2(t_cut *t_v, char **str, int count[3]);
void					ft_cut_flag_p2(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_cut_p2(t_cut *t_v, char **str, int count[3]);

void					ft_cut_init_s(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_s1(t_cut *t_v, char **str, int count[3]);
void					ft_cut_flag_s2(t_cut *t_v, char **str, int count[3]);
void					ft_cut_flag_s2_1(t_cut *t_v, char **str, int count[3]);
void					ft_cut_flag_s2_2(t_cut *t_v, char **str, int count[3]);

void					ft_cut_init_c(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_c1(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_c2(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_c2_1(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_c3(t_cut *t_v, char **str, int count[3]);

void					ft_cut_init_d(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_d1(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_d2(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_d3(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_cut_d3_1(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_d4(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_d5(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_d6(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_d6_1(t_cut *t_v, t_var **var,
		char **str, int count[3]);
void					ft_cut_flag_d6_2(t_cut *t_v, t_var **var, char **str,
		int count[3]);

int						cut_flag_number(char **str, int count[3],
		int *flag, char *c);
int						cut_flag_number_2(char **str, int count[3],
		int *flag, char *c);
int						cut_utf8_1(char *buf, int code);
void					cut_utf8_2(int *count, int *offset);
void					cut_utf8_3(int *count, int *offset);
void					cut_utf8_4(int *count, int *offset);

int						cut_flag_check(char **str, int count[3], int *nbr);
int						cut_flag_check2(int *nbr);
int						cut_flag_check3(int *nbr);
int						cut_flag_check4(int *nbr);
int						cut_flag_check5(int *nbr);
int						cut_flag_check6(int *nbr);
int						cut_flag_check7(int *nbr, char *c, char **str,
		int count[3]);

void					cut_recover_1(char *format, int tab[3],
		char *str, int var[3]);
void					cut_recover_2(int tab[3], char *str, int var[3]);
void					cut_recover_3(int tab[3], char *str, int var[3]);
void					cut_recover_4(char *format, int tab[3],
		char *str, int var[3]);
void					cut_recover_5(char *format, char *str, int var[3]);

void					attrib_erreur_conv(char **str, int count[3]);
void					add_flag_special(char *str, int var[3]);
void					add_flag_zero(char *str, int var[3]);
void					add_flag_one(char *format, char *str, int var[3]);
void					add_flag_two(char *format, char *str, int var[3]);
void					add_flag_three(char *format, char *str, int var[3]);
void					add_flag_four(char *format, char *str, int var[3]);
void					add_flag_five(char *format, char *str, int var[3]);
void					add_flag_six(char *format, char *str, int var[3]);
void					add_flag_seven(char *format, char *str, int var[3]);
void					attrib_c(char **str, t_var **var, int count[3]);
void					attrib_c_maj(char **str, t_var **var, int count[3]);
void					attrib_convers(char **str, t_var **var, int count[3]);
void					attrib_d(char **str, t_var **var, int count[3]);
void					attrib_d_char(char **str, t_var **var, int count[3]);
void					attrib_d_j(char **str, t_var **var, int count[3]);
void					attrib_d_ll(char **str, t_var **var, int count[3]);
void					attrib_d_maj(char **str, t_var **var, int count[3]);
void					attrib_d_short(char **str, t_var **var, int count[3]);
void					attrib_d_z(char **str, t_var **var, int count[3]);
void					attrib_h_h(char **str, t_var **var, int count[3]);
void					attrib_o(char **str, t_var **var, int count[3]);
void					attrib_o_char(char **str, t_var **var, int count[3]);
void					attrib_o_j(char **str, t_var **var, int count[3]);
void					attrib_o_maj(char **str, t_var **var, int count[3]);
void					attrib_o_short(char **str, t_var **var, int count[3]);
void					attrib_o_z(char **str, t_var **var, int count[3]);
void					attrib_p(char **str, t_var **var, int count[3]);
void					attrib_s(char **str, t_var **var, int count[3]);
void					attrib_s_maj(char **str, t_var **var, int count[3]);
void					attrib_u(char **str, t_var **var, int count[3]);
void					attrib_u_char(char **str, t_var **var, int count[3]);
void					attrib_u_j(char **str, t_var **var, int count[3]);
void					attrib_u_ll(char **str, t_var **var, int count[3]);
void					attrib_u_maj(char **str, t_var **var, int count[3]);
void					attrib_u_short(char **str, t_var **var, int count[3]);
void					attrib_u_z(char **str, t_var **var, int count[3]);
void					attrib_x(char **str, t_var **var, int count[3]);
void					attrib_x_l(char **str, t_var **var, int count[3]);
void					attrib_x_lmaj(char **str, t_var **var, int count[3]);
void					attrib_x_char(char **str, t_var **var, int count[3]);
void					attrib_x_maj(char **str, t_var **var, int count[3]);
void					attrib_x_maj_char(char **str, t_var **var,
		int count[3]);
void					attrib_x_maj_short(char **str, t_var **var,
		int count[3]);
void					attrib_x_short(char **str, t_var **var, int count[3]);
void					choix_add_flag(char *format, char *str, int var[3]);
void					recover_percent(char *format, char *str, int len,
		int *tab);
void					recup_var(t_var **tab, int nbr_var, va_list liste);
void					replace_char(char **str, t_var **var, va_list liste,
		int *tab);

#endif
