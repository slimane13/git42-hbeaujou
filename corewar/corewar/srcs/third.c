/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 14:58:14 by dbousque          #+#    #+#             */
/*   Updated: 2016/01/31 18:12:31 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <limits.h>

int		create_start_processes(t_vm *vm)
{
	t_list	*tmp;
	int		i;

	i = 0;
	while (i < vm->nb_players)
	{
		tmp = ft_lstnew(new_process(vm->players[i]->start, 0),
															sizeof(t_process));
		if (!tmp)
			return (0);
		if (!vm->processes)
			ft_lstaddend(&vm->processes, tmp);
		else
			ft_lstadd(&vm->processes, tmp);
		((t_process*)vm->processes->content)->remaining_cycles =
				get_cycles_for_opcode(*((t_process*)tmp->content)->next_instr);
		((t_process*)vm->processes->content)->registres[0] =
														vm->players[i]->number;
		((t_process*)vm->processes->content)->carry = 0;
		i++;
	}
	return (1);
}

void	update_cycle_to_die(int total_nb_live, int *cycle_to_die,
												int *to_die_iter, int *checks)
{
	if (total_nb_live >= NBR_LIVE)
	{
		*cycle_to_die -= CYCLE_DELTA;
		*checks = MAX_CHECKS;
	}
	else
		(*checks)--;
	*to_die_iter = *cycle_to_die;
}

void	remove_from_list(t_vm *vm, t_list *parent, t_list *tmp)
{
	if (parent)
		parent->next = tmp->next;
	else
		vm->processes = tmp->next;
}

void	delete_dead_processes(t_vm *vm, int *to_die_iter,
					int *cycle_to_die, int *checks)
{
	t_list		*tmp;
	t_list		*parent;
	int			total_nb_live;
	t_process	*proc;

	total_nb_live = 0;
	parent = NULL;
	tmp = vm->processes;
	while (tmp)
	{
		proc = ((t_process*)tmp->content);
		if (proc->nb_live == 0)
			remove_from_list(vm, parent, tmp);
		else
		{
			total_nb_live += ((t_process*)tmp->content)->nb_live;
			((t_process*)tmp->content)->nb_live = 0;
			parent = tmp;
		}
		tmp = tmp->next;
	}
	update_cycle_to_die(total_nb_live, cycle_to_die, to_die_iter, checks);
	vm->last_verif = vm->current_cycle;
}

void	increment_next_instr(t_vm *vm, t_process *process, int nb)
{
	int				i;
	unsigned char	*addr;

	if (PRINT_INSTR)
	{
		ft_printf("ADV %d (0x%04x -> 0x%04x) ", nb,
	process->next_instr - vm->memory, process->next_instr - vm->memory + nb);
		i = 0;
		addr = process->next_instr;
		while (i < nb)
		{
			ft_printf("%02x ", *addr);
			addr = next_instr(vm, addr);
			i++;
		}
		ft_putchar('\n');
	}
	while (nb > 0)
	{
		if (process->next_instr < vm->memory + MEM_SIZE - 1)
			process->next_instr++;
		else
			process->next_instr = vm->memory;
		nb--;
	}
}
