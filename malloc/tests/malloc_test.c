#include <ft_malloc.h>

int			main(void)
{
	char	*str;
	char	*str2;
	int		i;

	str = (char *)ft_malloc(sizeof(char) * 10);
	// printf("str = %p\n", str);
	// printf("%i\n", (int)*(str - 4));
	if (str)
	{
		i = 0;
		while (i < 9)
		{
			str[i] = 'a' + i;
			i++;
		}
		str[i] = '\0';
		printf("%s\n", str);
	}
	else
	{
		printf("Erreur malloc str\n");
	}

	str2 = (char *)ft_malloc(sizeof(char) * 10);
	// printf("str2 = %p\n", str2);
	if (str2)
	{
		i = 0;
		while (i < 9)
		{
			str2[i] = 'c' + i;
			i++;
		}
		str2[i] = '\0';

		printf("%p => %s\n", str, str);
		printf("%p => %s\n", str2, str2);
	}
	else
	{
		printf("Erreur malloc str2\n");
	}

	i = 0;
	while (i < 4079)
	{
		printf("%i : %d\n", i, (str[i]));
		i++;
	}


	return (0);
}
