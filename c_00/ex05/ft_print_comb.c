/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:36:53 by hna               #+#    #+#             */
/*   Updated: 2020/01/23 16:12:27 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchars(char i, char j, char k)
{
	write(1, &i, 1);
	write(1, &j, 1);
	write(1, &k, 1);
	if (i == '7' && j == '8' && k == '9')
	{
		return ;
	}
	write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	int i;
	int j;
	int k;

	i = '0';
	j = '1';
	k = '2';
	while (i < j)
	{
		j = i + 1;
		while (j < k)
		{
			k = j + 1;
			while (k <= '9')
			{
				ft_putchars(i, j, k);
				k++;
			}
			j++;
		}
		i++;
	}
}
