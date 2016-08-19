#include <ft_malloc.h>

int			main(void)
{
	char	*str;
	int j;

	for (int i = 0; i < 200; i++)
	{
		str = (char *)ft_malloc(sizeof(char) * 500);
		if (!str)
		{
			printf("Str doesn't exist\n");
			return (-1);
		}
		j = -1;
		while (++j < 409)
			str[j] = 'a';
		str[j] = '\0';
		printf("%d %s\n", i, str);
	}
	return (0);
}
