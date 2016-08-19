#include <stdio.h>
#include <stdlib.h>

// gcc tests/sizeof_test.c ; ./a.out ; rm a.out

int				main(void)
{

	printf("sizeof(char) : %zu\n", sizeof(char));		// 1
	printf("sizeof(int) : %zu\n", sizeof(int));			// 4
	printf("sizeof(size_t) : %zu\n", sizeof(size_t));	// 4
	printf("sizeof(char *) : %zu\n", sizeof(char *));	// 8
	printf("sizeof(int *) : %zu\n", sizeof(int *));		// 8
	printf("sizeof(char **) : %zu\n", sizeof(char **));	// 8

	int				*str;
	int				i;
	char			*str2;

	str = (int *)malloc(sizeof(int) * 10);
	i = 0;
	while (i < 9)
	{
		str[i] = 1 + i;
		i++;
	}
	str[i] = 0;

	i = 0;
	while (str[i] != 0)
	{
		printf("%x %i\n", (str + i), str[i]);
		i++;
	}

	str2 = (char *)str;
	i = 0;
	while (i < (4 * 9))
	{
		printf("%x %c\n", (str2 + i), '0' + str2[i]);
		i++;		
	}

	return (0);
}