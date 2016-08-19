#include <ft_malloc.h>

int			main(void)
{
	char	*str;
	int j;

	for (int i = 0; i < 200000; i++)
	{
		str = (char *)ft_malloc(sizeof(char) * 40);
		if (!str)
		{
			printf("str doesnt exist\n");
			return (1);
		}
		j = -1;
		while (++j < 39)
			str[j] = 'a';
		str[j] = '\0';
		printf("%d %s\n", i, str);
	}
}
