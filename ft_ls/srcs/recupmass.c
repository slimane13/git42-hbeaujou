/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recupmass.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 16:15:27 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/13 16:32:43 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_long	*ft_recup_long(struct stat buf, t_option *op)
{
	t_long			*elem;
	struct passwd	*pass_uid;
	struct group	*pass_gid;

	if ((elem = (t_long *)malloc(sizeof(t_long))) != NULL)
	{
		pass_uid = getpwuid(buf.st_uid);
		pass_gid = getgrgid(buf.st_gid);
		elem->time = ft_strdup(ctime(&buf.st_mtime));
		if (op->date == 2)
			elem->time = ft_strdup(ctime(&buf.st_birthtime));
		else if (op->date == 3)
			elem->time = ft_strdup(ctime(&buf.st_atime));
		if (op->uid == 0)
			elem->uid_name = ft_strdup("");
		else if (pass_uid)
			elem->uid_name = ft_strdup(pass_uid->pw_name);
		else
			elem->uid_name = ft_itoa(buf.st_uid);
		if (pass_gid)
			elem->gid_name = ft_strdup(pass_gid->gr_name);
		else
			elem->gid_name = ft_itoa(buf.st_gid);
	}
	return (elem);
}
