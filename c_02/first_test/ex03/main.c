#include <stdio.h>

int		ft_str_is_numeric(char *str);

int		main(void)
{
	char	str1[10] = "abc3fg";
	char	str2[10] = "1234";
	char	str3[10] = "";
	int		res;

	res = ft_str_is_numeric(str1);
	printf("str:%s res:%d\n", str1, res);
	res = ft_str_is_numeric(str2);
	printf("str:%s res:%d\n", str2, res);
	res = ft_str_is_numeric(str3);
	printf("str:%s res:%d\n", str3, res);
	return (0);
}
