#include <stdio.h>

char	*ft_strlowcase(char *str);

int		main(void)
{
	char str1[10] = "abCDe0 ";
	ft_strlowcase(str1);

	printf("%s\n", str1);
	return (0);
}
