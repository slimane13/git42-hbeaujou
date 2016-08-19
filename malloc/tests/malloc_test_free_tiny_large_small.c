#include <ft_malloc.h>

int			main(void)
{
	char	*str;
	char	*str2;
	int		*large_str;

	int j;

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
	printf("%s\n", str);

	str2 = (char *)ft_malloc(sizeof(char) * 400);
	if (!str2)
	{
		printf("str doesnt exist\n");
		return (1);
	}
	j = -1;
	while (++j < 399)
		str2[j] = 'a';
	str2[j] = '\0';
	printf("%s\n", str2);

	large_str = (int *)ft_malloc(sizeof(int) * 400000);
	if (!large_str)
	{
		printf("str doesnt exist\n");
		return (1);
	}
	j = -1;
	while (++j < 400000)
		large_str[j] = 11;
	j = -1;
	while (++j < 400000)
		printf("%d ", large_str[j]);
	printf("\n");


	ft_free(str2);
	ft_free(str);
	ft_free(large_str);
}
