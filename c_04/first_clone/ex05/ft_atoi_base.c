/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 20:07:44 by hna               #+#    #+#             */
/*   Updated: 2020/01/28 20:52:42 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				check_base(char *base)
{
	long long int base_len;
	long long int i;
	long long int j;

	i = -1;
	base_len = 0;
	while (base[base_len])
		base_len++;
	if (base_len <= 1)
		return (0);
	while (++i < base_len)
		if (base[i] == ' ' || base[i] == '+' || base[i] == '-' ||
				(base[i] >= 9 && base[i] <= 13))
			return (0);
	i = -1;
	while (++i < base_len - 1)
	{
		j = i;
		while (++j < base_len)
		{
			if (base[i] == base[j])
				return (0);
		}
	}
	return (1);
}

int				find_idx(char target, char *ref)
{
	int i;

	i = 0;
	while (ref[i])
	{
		if (target == ref[i])
			return (i);
		i++;
	}
	return (-1);
}

long long int	str_to_int(char *str, char *base)
{
	int				i;
	long long int	res;
	long long int	sign;
	long long int	base_len;

	base_len = 0;
	res = 0;
	i = 0;
	sign = 1;
	while (base[base_len])
		base_len++;
	if (str[0] == '-')
	{
		sign = -1 * sign;
		i++;
	}
	while (str[i])
	{
		res = res * base_len + (long long int)(find_idx(str[i], base));
		i++;
	}
	return (sign * res);
}

int				ft_atoi_base(char *str, char *base)
{
	long long int	except;
	int				ret;
	int				i;

	i = 0;
	if (check_base(base) == 0)
		return (0);
	while (str[i])
	{
		if (find_idx(str[i], base) == -1)
			return (0);
		i++;
	}
	except = str_to_int(str, base);
	if (except == -2147483648)
		return (-2147483648);
	ret = (int)except;
	return (ret);
}
