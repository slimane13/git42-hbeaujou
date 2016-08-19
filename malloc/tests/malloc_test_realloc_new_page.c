#include <ft_malloc.h>

int			main(void)
{
	char	*str;
	char	*str2;
	char	*deb;
	int i;

	str = (char *)ft_malloc(sizeof(char) * 3);
	if (!str)
	{
		printf("str don't exist\n");
		return (-1);
	}

	deb = str - 17;

	i = 0;
	while (i < 3)
	{
		str[i]= 'a';
		i++;
	}

	str2 = (char *)ft_malloc(sizeof(char) * 3);
	if (!str2)
	{
		printf("str2 don't exist\n");
		return (-1);
	}

	i = 0;
	while (i < 3)
	{
		str2[i]= 'b';
		i++;
	}

	printf("======= BEFORE FIRST REALLOC =======\n");

	i = 0;
	while (i < 50)
	{
		printf("%d.    %p => %d\n", i, deb + i, (int)deb[i]);
		i++;
	}

	str = (char *)ft_realloc(str, 5);


	printf("\n\n\n======= AFTER FIRST REALLOC =======\n");

	i = 0;
	while (i < 50)
	{
		printf("%d.    %p => %d\n", i, deb + i, (int)deb[i]);
		i++;
	}

	str = (char *)ft_realloc(str, 5000);


	printf("\n\n\n======= AFTER SECOND REALLOC =======\n");
	i = 0;
	while (i < 50)
	{
		printf("%d.    %p => %d\n", i, deb + i, (int)deb[i]);
		i++;
	}

	deb = str - 17;

	printf("\n\n\n======= AFTER SECOND REALLOC (BIS) =======\n");
	i = 0;
	while (i < 50)
	{
		printf("%d.    %p => %d\n", i, deb + i, (int)deb[i]);
		i++;
	}

	str2 = (char *)ft_realloc(str2, 5000);

	ft_free(str);
	ft_free(str2);
}
