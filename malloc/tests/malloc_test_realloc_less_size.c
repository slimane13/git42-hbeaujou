#include <ft_malloc.h>

int			main(void)
{
	char	*str;
	int i;

	str = (char *)ft_malloc(sizeof(char) * 40);
	if (!str)
	{
		printf("str don't exist\n");
		return (-1);
	}

	i = 0;
	while (i < 40)
	{
		str[i]= 'a';
		i++;
	}

	ft_realloc(str, 3);

	i = -17;
	while (i < 10)
	{
		printf("%p => %d\n", str, (int)str[i]);
		i++;
	}

	ft_free(str);
}
