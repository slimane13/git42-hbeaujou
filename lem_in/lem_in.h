/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 14:20:35 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/04 12:47:23 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "./ft_printf/ft_printf.h"

typedef struct	s_room
{
	char		*name;
	int			ant;
	t_room		*t_nexts;
	t_room		*t_previous;
}				t_room;
