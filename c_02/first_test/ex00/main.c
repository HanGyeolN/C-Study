#include <stdio.h>

char	*ft_strcpy(char *dest, char *src);

int		main(void)
{
	char s2[10];

	ft_strcpy(s2, "hello");
	printf("%s\n", s2);
	return (0);
}
