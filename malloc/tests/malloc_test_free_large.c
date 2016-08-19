#include <ft_malloc.h>

int			main(void)
{
	char	*str;
	int j;

	str = (char *)ft_malloc(sizeof(char) * 40000);
	if (!str)
	{
		printf("str doesnt exist\n");
		return (1);
	}
	j = -1;
	while (++j < 39999)
		str[j] = 'a';
	str[j] = '\0';
	printf("%s\n", str);

	ft_free(str);

}
