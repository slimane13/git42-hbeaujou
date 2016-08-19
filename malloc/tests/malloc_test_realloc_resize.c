#include <ft_malloc.h>

int			main(void)
{
	char	*str;
	int i;

	str = (char *)ft_malloc(sizeof(char) * 3);
	if (!str)
	{
		printf("str don't exist\n");
		return (-1);
	}

	i = 0;
	while (i < 3)
	{
		str[i]= 'a';
		i++;
	}

	str = ft_realloc(str, 5);

	i = -17;
	while (i < 10)
	{
		printf("%d.    %p => %d\n", i + 17, str, (int)str[i]);
		i++;
	}

	ft_free(str);
}
