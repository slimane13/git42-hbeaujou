/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eigth.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 15:43:11 by dbousque          #+#    #+#             */
/*   Updated: 2016/01/31 18:56:43 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <limits.h>

int			run_vm(t_vm *vm, int dump)
{
	int		cycle_to_die;
	int		to_die_iter;
	int		checks;

	init_vars(&cycle_to_die, &to_die_iter, &checks);
	if (!(create_start_processes(vm)))
		return (0);
	while (1)
	{
		execute_processes(vm);
		if (to_die_iter <= 0)
			delete_dead_processes(vm, &to_die_iter, &cycle_to_die, &checks);
		if (!vm->processes)
			return (1);
		if (checks == 0)
			decrement_cycle_to_die(&cycle_to_die, &to_die_iter, &checks);
		if (vm->current_cycle == dump)
			dumpmemory(vm->memory);
		vm->current_cycle++;
		to_die_iter--;
		if (PRINT_INSTR)
			ft_printf("It is now cycle %d\n", vm->current_cycle);
	}
	return (1);
}

t_player	*get_player_with_number(t_vm *vm, int numb)
{
	int		i;

	i = 0;
	while (i < vm->nb_players)
	{
		if (vm->players[i]->number == numb)
			return (vm->players[i]);
		i++;
	}
	ft_putendl_fd("BIG ERROR !\n", 2);
	return (NULL);
}

void		print_winner(t_vm *vm)
{
	t_player	*player;

	player = get_player_with_number(vm, vm->last_player);
	ft_printf("le joueur %d(%s) a gagne\n", player->number, player->name);
}

void		add_champion(char *filename, t_vm *vm, int n)
{
	char	*champion;
	int		size;

	champion = get_file_content(filename, &size);
	add_player_to_vm(vm, get_player_from_file(vm, champion, size, n));
	free(champion);
}

int			get_num(char *str, int can_be_neg)
{
	int				i;
	int				sign;
	const char		*error = "Illegal numeric argument\n";

	sign = 1;
	i = 0;
	if (*str == '-' && can_be_neg)
	{
		sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		i = i * 10 + *str - '0';
		str++;
	}
	if (*str)
		exit(write(2, error, ft_strlen(error)));
	return (i * sign);
}
