/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 16:22:38 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/04/09 19:03:10 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

int main(int argc, char **argv)
{
	int i;
	int j;
	char *line;
	float **map;

	i = 0;
	map = (float **)malloc(sizeof(float *) * WINDOW_HEIGHT);
	while (i < WINDOW_HEIGHT)
	{
		map[i] = (float *)malloc(sizeof(float) * WINDOW_WIDTH);
		i++;
	}

	i = 0;
	j = 0;
	init_map(map);
	put_in_map(map, argv);
	printf("\n");
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			if (map[i][j] != 0)
				printf("\e[1;34m%.2f \e[0m", map[i][j]);
			else
				printf("%.2f ", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	init_map(float **map)
{
	int i = 0;
	int j = 0;

	while (i < WINDOW_WIDTH)
	{
		j = 0;
		while (j < WINDOW_HEIGHT)
		{
			map[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	put_in_map(float **map, char **argv)
{
	int fd;
	int start;
	int i;
	int tmp;
	char *line;
	char *sub;

	i = 0;
	start = 0;
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &line);
	close(argv[1]);
	printf("\n%s\n\n", line);
	while (line[i])
	{
		if (line[i] == '(')
			start = i;
		else if (line[i] == ')')
		{
			sub = ft_strsub_slim(line, start, i - start + 1);
			apply_point_to_map(sub, map);
		}
		i++;
	}
}

void	apply_point_to_map(char *sub, float **map)
{
	int i;
	int width;
	int height;
	int start;
	float z;
	char *tmp;

	i = 1;
	start = 1;
	while (sub[i] != ',')
		i++;
	tmp = ft_strsub_slim(sub, start, i - start);
	width = ft_atoi(tmp);
	i++;
	start = i;
	while (sub[i] != ',')
		i++;
	tmp = ft_strsub_slim(sub, start, i - start);
	height = ft_atoi(tmp);
	i++;
	start = i;
	while (sub[i] != ')')
		i++;
	tmp = ft_strsub_slim(sub, start, i - start);
	z = atof(tmp);
	width = width / 1000;
	height = height / 1000;
	z = z / 1000;
	map[width][height] = z;
	printf("%d / %d / %f\n", width, height, z);
}

char	*ft_strsub_slim(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	res = (char*)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	i = start;
	while (i < start + (int)len)
	{
		res[i - start] = s[i];
		i++;
	}
	res[i - start] = '\0';
	return (res);
}

void	check_around_point(float **map)
{
}
