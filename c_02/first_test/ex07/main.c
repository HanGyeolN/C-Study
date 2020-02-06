#include <stdio.h>

char	*ft_strupcase(char *str);

int		main(void)
{
	char str1[10] = "abCde0 ";
	ft_strupcase(str1);

	printf("%s\n", str1);
	return (0);
}
