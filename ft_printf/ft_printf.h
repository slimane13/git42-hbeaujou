/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 15:28:05 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/12 17:56:07 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>       ///////////////////////////////////////
#include <ctype.h>	// pour iscntrl() a recoder
#include <stdarg.h>

typedef struct		s_var
{
	int				entier;
	char			carac;
	char			*string;
}					t_var;

int		check_conver(char *format, int var[3]);
int		check_flag_number(char **str, int count[3], int *nbr, char *c);
int		run_var(char *str, char c);

void	add_flag_one(char *format, char *str, int var[3]);
void	add_flag_two(char *format, char *str, int var[3]);
void	add_flag_three(char *format, char *str, int var[3]);
void	add_flag_four(char *format, char *str, int var[3]);
void	add_flag_five(char *format, char *str, int var[3]);
void	attrib_alpha(char **str, t_var **var, int count[3]);
void	attrib_c(char **str, t_var **var, int count[3]);
void	attrib_convers(char **str, t_var **var, int count[3]);
void	attrib_d(char **str, t_var **var, int count[3]);
void	attrib_s(char **str, t_var **var, int count[3]);
void	choix_add_flag(char *format, char *str, int var[3]);
void	recover_percent(char *format, char *str, int len);
void	recup_var(t_var **tab, int nbr_var, va_list liste);
void	replace_char(char **str, t_var **var, va_list liste);
