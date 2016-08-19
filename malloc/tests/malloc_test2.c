#include <ft_malloc.h>

int			main(void)
{
	char	*str;
	char	*str2;
	char	*str3;
	char	*str4;
	char	*str5;
	char	*str6;
	char	*str7;
	char	*str8;
	char	*str9;
	char	*str10;
	char	*str11;
	char	*str12;

	str = (char *)ft_malloc(sizeof(char) * 40);
	ft_memset((void *)str, 'a', 39);
	str[39] = '\0';
	printf("%s\n", str);

	str2 = (char *)ft_malloc(sizeof(char) * 40);
	ft_memset((void *)str2, 'b', 39);
	str2[39] = '\0';
	printf("%s\n", str2);

	str3 = (char *)ft_malloc(sizeof(char) * 40);
	ft_memset((void *)str3, 'c', 39);
	str3[39] = '\0';
	printf("%s\n", str3);

	str4 = (char *)ft_malloc(sizeof(char) * 40);
	ft_memset((void *)str4, 'd', 39);
	str4[39] = '\0';
	printf("%s\n", str4);

	str5 = (char *)ft_malloc(sizeof(char) * 40);
	ft_memset((void *)str5, 'e', 39);
	str5[39] = '\0';
	printf("%s\n", str5);

	str6 = (char *)ft_malloc(sizeof(char) * 40);
	ft_memset((void *)str6, 'f', 39);
	str6[39] = '\0';
	printf("%s\n", str);

	str7 = (char *)ft_malloc(sizeof(char) * 40);
	ft_memset((void *)str7, 'g', 39);
	str7[39] = '\0';
	printf("%s\n", str7);

	str8 = (char *)ft_malloc(sizeof(char) * 40);
	ft_memset((void *)str8, 'h', 39);
	str8[39] = '\0';
	printf("%s\n", str8);

	str9 = (char *)ft_malloc(sizeof(char) * 40);
	ft_memset((void *)str9, 'i', 39);
	str9[39] = '\0';
	printf("%s\n", str9);

	str10 = (char *)ft_malloc(sizeof(char) * 40);
	ft_memset((void *)str10, 'j', 39);
	str10[39] = '\0';
	printf("%s\n", str10);

	str11 = (char *)ft_malloc(sizeof(char) * 40);
	ft_memset((void *)str11, 'k', 39);
	str11[39] = '\0';
	printf("%s\n", str11);

	str12 = (char *)ft_malloc(sizeof(char) * 40);
	ft_memset((void *)str12, 'l', 39);
	str12[39] = '\0';
	printf("%s\n", str12);

	return (0);
}
