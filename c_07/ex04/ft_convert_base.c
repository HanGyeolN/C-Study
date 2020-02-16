/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 10:57:26 by hna               #+#    #+#             */
/*   Updated: 2020/02/02 22:52:30 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_in(char c, char *base);
int		is_valid(char *base);
int		ft_strlen(char *str);

int		base_nbr_to_lint(char *nbr, char *base_from)
{
	int	ret;
	int	base_len;
	int	sign;
	int	i;

	sign = 1;
	i = 0;
	base_len = 0;
	ret = 0;
	while (base_from[base_len])
		base_len++;
	while (nbr[i] == ' ' || (9 <= nbr[i] && nbr[i] <= 13))
		i++;
	while (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			sign = -1 * sign;
		i++;
	}
	while (is_in(nbr[i], base_from) != -1)
	{
		ret = ret * base_len + is_in(nbr[i], base_from);
		i++;
	}
	return (sign * ret);
}

int		get_mem_size(int nbr, int base_len)
{
	int		mem_size;

	mem_size = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr = -1 * nbr;
		mem_size++;
	}
	while (nbr != 0)
	{
		nbr = nbr / base_len;
		mem_size++;
	}
	return (mem_size);
}

void	set_base_nbr(int nbr, char *base_to, char *dest, int size)
{
	int	i;
	int	base_len;
	int	mod;

	i = 0;
	base_len = ft_strlen(base_to);
	if (nbr == 0)
		dest[0] = '0';
	else if (nbr < 0)
	{
		dest[0] = '-';
		nbr = -1 * nbr;
	}
	while (nbr != 0)
	{
		mod = nbr % base_len;
		nbr = nbr / base_len;
		dest[size - i - 1] = base_to[mod];
		i++;
	}
	dest[size] = '\0';
}

char	*lint_to_base_nbr(int nbr, char *base_to)
{
	int		str_size;
	char	*ret;
	int		base_len;

	base_len = ft_strlen(base_to);
	str_size = get_mem_size(nbr, base_len);
	ret = (char *)malloc(sizeof(char) * str_size);
	set_base_nbr(nbr, base_to, ret, str_size);
	return (ret);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long int	int_nbr;
	char			*ret;

	if (is_valid(base_from) == 0 || is_valid(base_to) == 0)
		return (0);
	int_nbr = base_nbr_to_lint(nbr, base_from);
	ret = lint_to_base_nbr((int)int_nbr, base_to);
	return (ret);
}
