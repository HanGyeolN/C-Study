/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 20:07:44 by hna               #+#    #+#             */
/*   Updated: 2020/02/06 11:18:30 by hna              ###   ########.fr       */
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

	i = -1;
	while (ref[++i])
		if (target == ref[i])
			return (i);
	return (-1);
}

long long int	check_str(char *str, char *base, int *idx)
{
	int				i;
	int				flag;
	long long int	sign;

	i = -1;
	flag = 0;
	sign = 1;
	while (find_idx(str[++i], base) == -1)
	{
		if (str[i] == '+' || str[i] == '-')
		{
			flag = 1;
			if (str[i] == '-')
				sign = -1 * sign;
		}
		else if (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
		{
			if (flag == 1)
				return (0);
		}
		else
			return (0);
	}
	*idx = i;
	return (sign);
}

long long int	str_to_int(char *str, char *base)
{
	int				i;
	long long int	res;
	long long int	base_num;
	long long int	base_len;
	long long int	sign;

	res = 0;
	base_len = 0;
	while (base[base_len])
		base_len++;
	sign = check_str(str, base, &i);
	while (find_idx(str[i], base) != -1)
	{
		base_num = find_idx(str[i], base);
		if (base_num == -1)
			return (0);
		res = res * base_len + (long long int)base_num;
		i++;
	}
	return (sign * res);
}

int				ft_atoi_base(char *str, char *base)
{
	long long int	long_int;
	int				i;

	i = 0;
	if (check_base(base) == 0)
		return (0);
	long_int = str_to_int(str, base);
	if (long_int == -2147483648)
		return (-2147483648);
	else
		return (int)long_int;
}
