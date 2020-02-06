/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 10:48:44 by hna               #+#    #+#             */
/*   Updated: 2020/01/24 12:07:43 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
void	swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int idx;
	int i;
	int min;

	idx = 0;
	while (idx < size)
	{
		min = tab[idx];
		i = idx + 1;
		while (i < size)
		{
			if (tab[i] < min)
			{
				min = tab[i];
				swap(tab + idx, tab + i);
			}
			i++;
		}
		idx++;
	}
}

int main(void)
{
	int i;
	int arr[5] = { 2, 7, 1, 5, 1};

	i = 0;
	ft_sort_int_tab(arr, 5);
	while(i < 5)
	{
		printf("%d ", arr[i]);
		i++;
	}

}
