/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 15:54:53 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/09 14:54:05 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	modif_names(t_file **files)
{
	t_file	*tmp;
	int		max;
	int		p;

	max = 0;
	p = 0;
	tmp = *files;
	while (tmp)
	{
		p = ft_strlen(tmp->name);
		p = p + 8 - (p % 8);
		if (p > max)
			max = p;
		tmp = tmp->next;
	}
	tmp = *files;
	while (tmp)
	{
		p = ft_strlen(tmp->name);
		tmp->modif = ft_strdup(tmp->name);
		while (p < max)
		{
			tmp->modif = ft_strjoin(tmp->modif, " ");
			p++;
		}
		tmp = tmp->next;
	}
}

void	affiche_files_acone(t_file **files)
{
	int 	i;
	int		nb;
	t_file	*tmp;

	i = 0;
	nb = nbr_files(files);
	tmp = *files;
	while (tmp)
	{
		if ((i % 4 == 0 && i != 0) || i == nb - 1)
			ft_printf("%s\n", tmp->name);
		else
			ft_printf("%s", tmp->modif);
		i++;
		tmp = tmp->next;
	}
}

void	argc_one(t_file **files)
{
	DIR				*dir;
	struct dirent	*ent;
	t_file			*tmp;

	if ((dir = opendir ("./")) != NULL)
	{
		while ((ent = readdir (dir)) != NULL)
		{
			if (ft_strcmp(ent->d_name, ".") == 0 ||
					ft_strcmp(ent->d_name, "..") == 0)
				;
			else
			{
				tmp = new_file(ent->d_name);
				ft_lstaddend_file(files, tmp);
			}
		}
		closedir (dir);
	}
	else
		perror ("");
	modif_names(files);
	affiche_files_acone(files);
}

int		main(int ac, char **av)
{
	t_file			*files;
	t_file			*tmp;
	t_flag			*flag;

	if (ac == 1)
	{
		argc_one(&files);
		return EXIT_SUCCESS;
	}
	if(!(flag = (t_flag *)malloc(sizeof(t_flag))))
		return (0);
	files = NULL;
	parsing(av, &flag, &files);
	affiche_files(&files, &flag);
	///////////////// TEST DE LA STRUCT STAT OP /////////////////////////
	/*
	   struct stat sb;

	   if (stat(av[1], &sb) == -1) {
	   perror("stat");
	   exit(EXIT_FAILURE);
	   }

	   ft_printf("File type:                ");

	   switch (sb.st_mode & S_IFMT) {
	   case S_IFBLK:  ft_printf("block device\n");            break;
	   case S_IFCHR:  ft_printf("character device\n");        break;
	   case S_IFDIR:  ft_printf("directory\n");               break;
	   case S_IFIFO:  ft_printf("FIFO/pipe\n");               break;
	   case S_IFLNK:  ft_printf("symlink\n");                 break;
	   case S_IFREG:  ft_printf("regular file\n");            break;
	   case S_IFSOCK: ft_printf("socket\n");                  break;
	   default:       ft_printf("unknown?\n");                break;
	   }

	   ft_printf("I-node number:            %ld\n", (long) sb.st_ino);

	   ft_printf("Mode:                     %lo (octal)\n",
	   (unsigned long) sb.st_mode);

	   ft_printf("Link count:               %ld\n", (long) sb.st_nlink);
	   ft_printf("Ownership:                UID=%ld   GID=%ld\n",
	   (long) sb.st_uid, (long) sb.st_gid);

	   ft_printf("Preferred I/O block size: %ld bytes\n",
	   (long) sb.st_blksize);
	   ft_printf("File size:                %lld bytes\n",
	   (long long) sb.st_size);
	   ft_printf("Blocks allocated:         %lld\n",
	   (long long) sb.st_blocks);

	   ft_printf("Last status change:       %s", ctime(&sb.st_ctime));
	   ft_printf("Last file access:         %s", ctime(&sb.st_atime));
	   ft_printf("Last file modification:   %s", ctime(&sb.st_mtime));
	   */
	///////////////////////////// FIN DES TEST //////////////////////////

	exit(EXIT_SUCCESS);
}
