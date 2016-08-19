#include <ft_malloc.h>

int			main(void)
{
	char	*str;

	for (int i = 0; i < 500; i++)
	{
		str = (char *)ft_malloc(sizeof(char) * 409);
		if (!str)
		{
			printf("Str doesn't exist\n");
			return (-1);
		}
		printf("nb = %d\n", i);
	}
	return (0);
}
