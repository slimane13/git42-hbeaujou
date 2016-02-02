/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 15:32:03 by dbousque          #+#    #+#             */
/*   Updated: 2016/01/31 19:04:50 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <limits.h>

void	add_player_to_vm(t_vm *vm, t_player *player)
{
	static int	index = 0;

	if (index >= MAX_PLAYERS)
		exit(write(2, "More players\n", 13));
	vm->players[index] = player;
	vm->nb_players++;
	index++;
}

void	dumpmemory(unsigned char *memory)
{
	int		i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (i % 32 == 0)
			ft_printf("0x%04x : ", i);
		ft_printf("%02x ", memory[i]);
		i++;
		if (i % 32 == 0)
			ft_putstr("\n");
	}
	exit(1);
}

void	load_players_in_memory(t_vm *vm)
{
	int		decal;
	int		offset;
	int		i;

	ft_putendl("Introducing contestants...");
	decal = MEM_SIZE / vm->nb_players;
	offset = 0;
	i = 0;
	while (i < vm->nb_players)
	{
		ft_memcpy(vm->memory + offset, vm->players[i]->code,
													vm->players[i]->code_len);
		vm->players[i]->start = vm->memory + offset;
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
													vm->players[i]->number,
	vm->players[i]->code_len, vm->players[i]->name, vm->players[i]->comment);
		i++;
		offset += decal;
	}
}

t_vm	*init_vm(void)
{
	t_vm	*vm;

	if (!(vm = (t_vm*)malloc(sizeof(t_vm))))
		return (NULL);
	if (!(vm->players = (t_player**)malloc(sizeof(t_player*)
														* (MAX_PLAYERS + 1))))
		return (NULL);
	vm->players[MAX_PLAYERS] = NULL;
	vm->processes = NULL;
	if (!(vm->memory = (unsigned char*)malloc(sizeof(unsigned char)
																* MEM_SIZE)))
		return (NULL);
	vm->nb_players = 0;
	vm->current_cycle = 0;
	vm->last_verif = 0;
	vm->last_player = 0;
	return (vm);
}

int		get_cycles_for_opcode(int opcode)
{
	int		i;

	i = 0;
	while (g_op_tab[i].name)
	{
		if (g_op_tab[i].opcode == opcode)
			return (g_op_tab[i].nb_cycles);
		i++;
	}
	return (0);
}
