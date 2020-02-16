/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:52:26 by hna               #+#    #+#             */
/*   Updated: 2020/01/23 16:13:52 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ten_pow(int n)
{
	int result;

	result = 1;
	while (n > 0)
	{
		result = result * 10;
		n--;
	}
	return (result);
}

int		get_num_length(int i)
{
	int length;

	length = 0;
	if (i < 0)
		i = -i;
	while (i > 0)
	{
		i = i / 10;
		length++;
	}
	return (length);
}

void	write_int(int i)
{
	int w;
	int len;
	int div;
	int res;

	len = get_num_length(i);
	if (len < 2)
		write(1, "0", 1);
	while (len > 1)
	{
		div = ten_pow(len - 1);
		res = i / div;
		w = '0' + res;
		write(1, &w, 1);
		i = i - (res * div);
		len--;
	}
	w = '0' + i;
	write(1, &w, 1);
}

void	ft_print_comb2(void)
{
	int a;
	int b;

	a = 0;
	b = 1;
	while (a < 99)
	{
		b = a + 1;
		while (b < 100)
		{
			write_int(a);
			write(1, " ", 1);
			write_int(b);
			if (a == 98 && b == 99)
				break ;
			write(1, ", ", 2);
			b++;
		}
		a++;
	}
}
