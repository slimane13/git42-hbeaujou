/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 15:30:32 by dbousque          #+#    #+#             */
/*   Updated: 2016/01/31 19:04:33 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <limits.h>

t_process	*new_process(unsigned char *start, int cycle_creation)
{
	static int	nb = 1;
	t_process	*res;

	if (!(res = (t_process*)malloc(sizeof(t_process))))
		return (NULL);
	if (!(res->registres = (int*)malloc(sizeof(int) * REG_NUMBER)))
		return (NULL);
	res->next_instr = start;
	res->number = nb;
	nb++;
	res->carry = 0;
	res->remaining_cycles = 0;
	res->last_live = 0;
	res->creation_cycle = cycle_creation;
	res->nb_live = 0;
	res->current_opcode = *start;
	return (res);
}

int			to_little(int n)
{
	char bytes[4];

	bytes[3] = *(char *)&n;
	bytes[2] = *((char *)&n + 1);
	bytes[1] = *((char *)&n + 2);
	bytes[0] = *((char *)&n + 3);
	n = *(int *)bytes;
	return (n);
}

int			verify_file(char *contents, int size)
{
	const char		*no_magic = "No magic byte error!\n";
	const char		*no_name = "Champion has no name\n";
	const char		*no_comment = "Champion has no comment\n";
	const char		*champ_too_big = "Champion is too big\n";
	int				ch_size;

	if (*(int *)contents != (int)0xf383ea00)
		exit(write(2, no_magic, ft_strlen(no_magic)));
	contents += 4;
	if (size < PROG_NAME_LENGTH + 4 || !*contents)
		exit(write(2, no_name, ft_strlen(no_name)));
	contents += PROG_NAME_LENGTH;
	ch_size = to_little(*(int *)contents);
	contents += 4;
	if (size < PROG_NAME_LENGTH + 4 + COMMENT_LENGTH || !*contents)
		exit(write(2, no_comment, ft_strlen(no_comment)));
	if (size - PROG_NAME_LENGTH - 8 - COMMENT_LENGTH > CHAMP_MAX_SIZE)
		exit(write(2, champ_too_big, ft_strlen(champ_too_big)));
	if (size - PROG_NAME_LENGTH - 8 - COMMENT_LENGTH != ch_size)
		exit(write(2, "Incosistent .cor\n", ft_strlen("inconsistent .cor\n")));
	return (0);
}

char		*get_file_content(char *filename, int *res_size)
{
	char	buf[1024];
	char	*res;
	char	*tmp;
	int		ret;
	int		fd;

	if (!(res = malloc(sizeof(char) * 1)))
		exit(write(2, "No memory\n", 10));
	*res = 0;
	if ((fd = open(filename, O_RDONLY)) < 0)
		exit(write(2, "Bad param\n", 10));
	*res_size = 0;
	while ((ret = read(fd, buf, 1023)) > 0)
	{
		tmp = res;
		res = malloc(*res_size + ret + 1);
		ft_memcpy(res, tmp, *res_size);
		ft_memcpy(res + *res_size, buf, ret);
		free(tmp);
		*res_size += ret;
	}
	close(fd);
	return (res + verify_file(res, *res_size));
}

t_player	*get_player_from_file(t_vm *vm, char *content,
		int content_len, int number)
{
	t_player		*res;
	unsigned int	decal;

	(void)vm;
	decal = 4;
	if (!(res = (t_player*)malloc(sizeof(t_player))))
		exit(write(2, "No memory\n", 10));
	res->number = number;
	if (!(res->name = (char*)malloc(sizeof(char) * (PROG_NAME_LENGTH + 1))))
		return (NULL);
	res->name[PROG_NAME_LENGTH] = '\0';
	ft_memcpy(res->name, content + decal, PROG_NAME_LENGTH);
	decal += PROG_NAME_LENGTH + sizeof(int);
	if (!(res->comment = (char*)malloc(sizeof(char) * (COMMENT_LENGTH + 1))))
		exit(write(2, "No memory\n", 10));
	res->comment[COMMENT_LENGTH] = '\0';
	ft_memcpy(res->comment, content + decal, COMMENT_LENGTH);
	decal += COMMENT_LENGTH + 4;
	if (!(res->code = malloc(sizeof(unsigned char) * (content_len - decal))))
		return (NULL);
	ft_memcpy(res->code, content + decal - 4, content_len - decal + 4);
	res->code_len = content_len - decal + 4;
	res->start = NULL;
	return (res);
}
