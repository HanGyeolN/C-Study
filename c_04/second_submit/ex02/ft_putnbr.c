/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 11:04:38 by hna               #+#    #+#             */
/*   Updated: 2020/01/28 11:30:29 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long long int n;
	long long int div;
	long long int mod;

	n = (long long int)nb;
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
	}
	div = n / 10;
	mod = n % 10;
	if (n >= 10)
	{
		ft_putnbr(div);
	}
	ft_putchar(mod + '0');
}
