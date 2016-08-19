#include <ft_malloc.h>

int			main(void)
{
	char	*str_array[200];
	int		i;
	int 	j;

	i = -1;
	while (++i < 200)
	{
		str_array[i] = (char *)ft_malloc(sizeof(char) * 409);
		if (!(str_array[i]))
		{
			printf("str_array[%d] doesnt exist\n", i);
			return (1);
		}
		j = -1;
		while (++j < 408)
			str_array[i][j] = 'a';
		str_array[i][j] = '\0';
		printf("%s\n", str_array[i]);
	}

	i = -1;
	while (++i < 200)
	{
		ft_free(str_array[i]);
	}
}
