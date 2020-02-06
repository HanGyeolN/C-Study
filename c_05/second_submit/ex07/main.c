#include <stdio.h>

int	ft_find_next_prime(int nb);

int main(void)
{
	int nb;

	nb = -1;
	nb = ft_find_next_prime(nb);
	printf("%d\n", nb);
	return (0);
}
