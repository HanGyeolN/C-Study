#include <stdio.h>

int		ft_str_is_alpha(char *str);

int		main(void)
{
	char	str[10] = "abcdefg";
	char	str2[10] = "";
	char	str3[10] = "adf3";
	char	str4[10] = "4sdf";
	char	str5[10] = "\ns";
	char	str6[10] = "";
	int		res;
	int		i;

	res = ft_str_is_alpha(str4);
	printf("str:%s res:%d\n", str4, res);
	return (0);
}
