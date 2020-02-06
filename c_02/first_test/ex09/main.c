#include <stdio.h>

char	*ft_strcapitalize(char *str);

int		main(void)
{
	char str[100] = "3salut, comment tu vas ? 42mots quarante-deux; ci+et+un";

	ft_strcapitalize(str);
	printf("%s", str);
	return (0);
}
