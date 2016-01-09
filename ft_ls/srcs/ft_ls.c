/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 15:54:53 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/09 13:12:20 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	argc_one(void)
{
	int				i
	DIR				*dir;
	struct dirent	*ent;

	i = 0;
	if ((dir = opendir ("./")) != NULL)
	{
		while ((ent = readdir (dir)) != NULL)
		{
			if (ft_strcmp(ent->d_name, ".") == 0 ||
					ft_strcmp(ent->d_name, "..") == 0)
				;
			else
			{
				ft_printf ("%s", ent->d_name);
				if (i % 5 == 0)
					;
				else
					;
			}
			i++;
		}
		closedir (dir);
	}
	else
		perror ("");
}

int		main(int ac, char **av)
{
	t_file			*files;
	t_file			*tmp;
	t_flag			*flag;

	if (ac == 1)
	{
		argc_one();
		return EXIT_SUCCESS;
	}
	if(!(flag = (t_flag *)malloc(sizeof(t_flag))))
		return (0);
	files = NULL;
	parsing(av, &flag, &files);
	tmp = files;
	while (tmp)
	{
		ft_printf("fichier : %s\n", tmp->name);
		tmp = tmp->next;
	}
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
