/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 15:28:05 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/19 20:41:25 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>   //////////////////    ///////
#include <stdlib.h>
#include <ctype.h>	// pour iscntrl() a recoder
#include <stdarg.h>
#include <limits.h>

typedef struct		s_var
{
	int				entier;
	int				stars;
	unsigned char	u_carac;
	unsigned int	u_entier;
	unsigned short	u_short;
	unsigned long	u_long;
	unsigned long long	u_l_long;
	long			v_long;
	long long		v_l_long;
	short			v_short;
	char			carac;
	char			*string;
}					t_var;

extern int retour;

int		check_conver(char *format, int var[3]);
int		check_flag(char **str, int count[3], int *nbr, char *c);
int		check_flag_number(char **str, int count[3], int *nbr, char *c);
int		is_indice(int nb, int *tab);
int		run_var(char *str, char c);
int		ft_wtomb(char *s, wchar_t wchar);

int		ft_printf(char *format, ...);

void	add_flag_one(char *format, char *str, int var[3]);
void	add_flag_two(char *format, char *str, int var[3]);
void	add_flag_three(char *format, char *str, int var[3]);
void	add_flag_four(char *format, char *str, int var[3]);
void	add_flag_five(char *format, char *str, int var[3]);
void	add_flag_six(char *format, char *str, int var[3]);
void	attrib_c(char **str, t_var **var, int count[3]);
void	attrib_c_maj(char **str, t_var **var, int count[3]);
void	attrib_convers(char **str, t_var **var, int count[3]);
void	attrib_d(char **str, t_var **var, int count[3]);
void	attrib_d_char(char **str, t_var **var, int count[3]);
void	attrib_d_ll(char **str, t_var **var, int count[3]);
void	attrib_d_maj(char **str, t_var **var, int count[3]);
void	attrib_d_short(char **str, t_var **var, int count[3]);
void	attrib_h_h(char **str, t_var **var, int count[3]);
void	attrib_o(char **str, t_var **var, int count[3]);
void	attrib_o_char(char **str, t_var **var, int count[3]);
void	attrib_o_maj(char **str, t_var **var, int count[3]);
void	attrib_o_short(char **str, t_var **var, int count[3]);
void	attrib_p(char **str, t_var **var, int count[3]);
void	attrib_s(char **str, t_var **var, int count[3]);
void	attrib_u(char **str, t_var **var, int count[3]);
void	attrib_u_char(char **str, t_var **var, int count[3]);
void	attrib_u_ll(char **str, t_var **var, int count[3]);
void	attrib_u_maj(char **str, t_var **var, int count[3]);
void	attrib_u_short(char **str, t_var **var, int count[3]);
void	attrib_x(char **str, t_var **var, int count[3]);
void	attrib_x_char(char **str, t_var **var, int count[3]);
void	attrib_x_maj(char **str, t_var **var, int count[3]);
void	attrib_x_maj_char(char **str, t_var **var, int count[3]);
void	attrib_x_maj_short(char **str, t_var **var, int count[3]);
void	attrib_x_short(char **str, t_var **var, int count[3]);
void	choix_add_flag(char *format, char *str, int var[3]);
void	recover_percent(char *format, char *str, int len, int *tab);
void	recup_var(t_var **tab, int nbr_var, va_list liste);
void	replace_char(char **str, t_var **var, va_list liste, int *tab);
