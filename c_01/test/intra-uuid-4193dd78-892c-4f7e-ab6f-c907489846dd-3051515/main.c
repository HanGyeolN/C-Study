#include <stdio.h>
int main(void)
{
	int i;
	int arr[5] = { 1, 7, 3, 5, 2};

	i = 0;
	ft_sort_int_tab(arr, 5);
	while(i < 5)
	{
		printf("%d ", arr[i]);
		i++;
	}

}
