#include <ft_malloc.h>

int			main(void)
{
	char	*str;

	for (int i = 0; i < 2; i++)
		str = (char *)ft_malloc(sizeof(char) * 10);

	for (int i = 0; i < 15; i++)
		str = (char *)ft_malloc(sizeof(char) * 40);

	for (int i = 0; i < 5; i++)
		str = (char *)ft_malloc(sizeof(char) * 100);

	for (int i = 0; i < 100; i++)
		str = (char *)ft_malloc(sizeof(char) * 30);

	for (int i = 0; i < 10; i++)
		str = (char *)ft_malloc(sizeof(char) * (600 + (i * 30) / 7));


	printf("\n\n\n");

	show_alloc_mem();
}
