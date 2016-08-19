#include <ft_malloc.h>

int			main(void)
{
	char	*str;
	int j;

	for (int i = 0; i < 500; i++)
	{
		str = (char *)ft_malloc(sizeof(char) * 40);
		if (!str)
		{
			"Str doesn't exists\n";
			return (1);
		}
		j = -1;
		while (++j < 39)
			str[j] = 'a';
		str[j] = '\0';
		printf("%d %s\n", i, str);
		for (int i = 0; i < 10; i++)
		{
			str = (char *)ft_malloc(sizeof(char) * 409);
			if (!str)
			{
				"Str doesn't exists\n";
				return (1);
			}
		}
	}
}
