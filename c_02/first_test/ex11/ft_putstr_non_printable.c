/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 11:05:53 by hna               #+#    #+#             */
/*   Updated: 2020/01/26 12:36:34 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

char	ft_hex_convert(int dec)
{
	char ret;

	if (dec == 10)
		return ('a');
	else if (dec == 11)
		return ('b');
	else if (dec == 12)
		return ('c');
	else if (dec == 13)
		return ('d');
	else if (dec == 14)
		return ('e');
	else if (dec == 15)
		return ('f');
	else
	{
		ret = '0' + dec;
		return (ret);
	}
}

void	put_hex(int dec)
{
	char	ret;
	int		div;
	int		mod;

	div = 0;
	mod = 0;
	ft_div_mod(dec, 16, &div, &mod);
	write(1, "\\", 1);
	ret = ft_hex_convert(div);
	write(1, &ret, 1);
	ret = ft_hex_convert(mod);
	write(1, &ret, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((0 < str[i] && str[i] < 32) || str[i] == 127)
			put_hex(str[i]);
		else
			write(1, str + i, 1);
		i++;
	}
}
