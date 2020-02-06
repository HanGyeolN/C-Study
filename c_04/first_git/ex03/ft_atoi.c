/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:38:34 by hna               #+#    #+#             */
/*   Updated: 2020/01/28 17:52:23 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				check_type(char c)
{
	if (c >= '0' && c <= '9')
		return (3);
	else if (c == ' ' || (c >= 9 && c <= 13) || c == '+')
		return (2);
	else if (c == '-')
		return (1);
	else
		return (0);
}

long long int	str_to_int(char *str)
{
	int				i;
	long long int	res;
	long long int	sign;

	res = 0;
	i = 0;
	sign = 1;
	while (check_type(str[i]) != 3)
	{
		if (check_type(str[i]) == 1)
		{
			sign = -1 * sign;
			i++;
		}
		else if (check_type(str[i]) == 2)
			i++;
		else if (check_type(str[i]) == 0)
			return (0);
	}
	while (check_type(str[i]) == 3)
	{
		res = res * 10 + (long long int)(str[i] - '0');
		i++;
	}
	return (sign * res);
}

int				ft_atoi(char *str)
{
	long long int	n;
	int				ret;

	n = str_to_int(str);
	ret = n;
	if (n == -2147483648)
		return (-2147483648);
	else
		return (ret);
}
