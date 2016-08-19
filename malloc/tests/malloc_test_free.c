#include <ft_malloc.h>

int			main(void)
{
	char	*str;
	char	*str2;
	char	*str3;
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

	str2 = (char *)ft_malloc(sizeof(char) * 40);
	if (!str2)
	{
		printf("str2 doesnt exist\n");
		return (1);
	}
	j = -1;
	while (++j < 39)
		str2[j] = 'a';
	str2[j] = '\0';
	printf("%s\n", str2);

	printf("Before ft_free(str2)\n");
	ft_free(str2);
	printf("After ft_free(str2)\n");

	j = -1;
	while (++j < 40)
		printf("%p => %d\n", str2 + j, (int)str2[j]);


	printf("Before ft_free(str)\n");
	ft_free(str);
	j = -1;
	printf("After ft_free(str)\n");

	// while (++j < 40)
	// 	printf("%p => %d\n", str + j, (int)str[j]);


	printf("HERE 4\n");
	str3 = (char *)ft_malloc(sizeof(char) * 40);
	printf("HERE 5\n");
	if (!str3)
	{
		printf("str3 doesnt exist\n");
		return (1);
	}
	j = -1;
	while (++j < 39)
		str3[j] = 'a';
	str3[j] = '\0';
	printf("%s\n", str3);

	printf("Before ft_free(str3)\n");
	ft_free(str3);
	printf("After ft_free(str3)\n");

}
