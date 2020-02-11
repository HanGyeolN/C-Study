/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 19:31:34 by hna               #+#    #+#             */
/*   Updated: 2020/02/09 12:35:05 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

long long int	ft_strlen(char *str)
{
	long long int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int				check_base(char *base)
{
	long long int base_len;
	long long int i;
	long long int j;

	i = -1;
	base_len = ft_strlen(base);
	if (base_len <= 1)
		return (0);
	while (++i < base_len)
		if (base[i] == '+' || base[i] == '-')
			return (0);
	i = 0;
	while (i < base_len - 1)
	{
		j = i + 1;
		while (j < base_len)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char			*int_to_str_base(int nbr, char *base, char *str)
{
	int				i;
	long long int	n;
	long long int	div;
	long long int	mod;
	long long int	base_len;

	i = 0;
	n = (long long int)nbr;
	base_len = ft_strlen(base);
	if (nbr < 0)
		n = -n;
	div = n / base_len;
	mod = n % base_len;
	while (div != 0)
	{
		str[i++] = base[mod];
		mod = div % base_len;
		div = div / base_len;
	}
	str[i] = base[mod];
	if (nbr < 0)
		str[++i] = '-';
	str[++i] = '\0';
	return (str);
}

char			*ft_itoa_base(int nbr, char *base, int malloc_size)
{
	char			*str_nbr;

	str_nbr = (char *)malloc(malloc_size * sizeof(char));
	if (check_base(base) == 0)
	{
		ft_putstr_err("[-] : plase check the base : if_itoa_base.c");
		return (0);
	}
	int_to_str_base(nbr, base, str_nbr);
	return (str_nbr);
}
