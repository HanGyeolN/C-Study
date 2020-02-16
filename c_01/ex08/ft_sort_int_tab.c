/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 10:48:44 by hna               #+#    #+#             */
/*   Updated: 2020/01/24 11:51:49 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
