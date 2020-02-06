#include <stdio.h>

int		ft_str_is_lowercase(char *str);

int		main(void)
{
	char	str1[10] = "abcfg";
	char	str2[10] = "abcDe";
	char	str3[10] = "";
	int		res;

	res = ft_str_is_lowercase(str1);
	printf("str:%s res:%d\n", str1, res);
	res = ft_str_is_lowercase(str2);
	printf("str:%s res:%d\n", str2, res);
	res = ft_str_is_lowercase(str3);
	printf("str:%s res:%d\n", str3, res);
	return (0);
}
