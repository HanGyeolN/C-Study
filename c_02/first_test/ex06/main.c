#include <stdio.h>

int		ft_str_is_printable(char *str);

int		main(void)
{
	char	str1[10] = "ABCDE";
	char	str2[10] = "AB\nDe";
	char	str3[10] = "";
	int		res;

	res = ft_str_is_printable(str1);
	printf("str:%s res:%d\n", str1, res);
	res = ft_str_is_printable(str2);
	printf("str:%s res:%d\n", str2, res);
	res = ft_str_is_printable(str3);
	printf("str:%s res:%d\n", str3, res);
	return (0);
}
