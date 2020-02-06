/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:22:08 by hna               #+#    #+#             */
/*   Updated: 2020/01/23 16:23:33 by hna              ###   ########.fr       */
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

void	write_int(int nb)
{
	int i;
	int w;
	int len;
	int div;
	int res;

	i = nb;
	len = get_num_length(i);
	if (i < 0)
	{
		write(1, "-", 1);
		i = -i;
	}
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

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else
		write_int(nb);
}
