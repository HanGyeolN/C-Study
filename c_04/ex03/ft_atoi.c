/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:38:34 by hna               #+#    #+#             */
/*   Updated: 2020/01/29 13:14:26 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char			ft_type(char c)
{
	if (c >= '0' && c <= '9')
		return ('d');
	else if (c == ' ' || (c >= 9 && c <= 13))
		return ('s');
	else if (c == '-')
		return ('m');
	else if (c == '+')
		return ('p');
	else 
		return (0);
}

int				check_str(char *str)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while (ft_type(str[i]) != 'd')
	{
		if (ft_type(str[i]) == 'p' || ft_type(str[i]) == 'm')
			flag = 1;
		else if (flag == 1 && ft_type(str[i]) == 's')
			return (0);
		else if (ft_type(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

long long int	str_to_int(char *str)
{
	int				i;
	long long int	res;
	long long int	sign;

	res = 0;
	sign = 1;
	i = 0;
	if (check_str(str) == 0)
		return (0);
	while (ft_type(str[i]) != 'd')
	{
		if (str[i] == '-')
			sign = -1 * sign;
		i++;
	}
	while (ft_type(str[i]) == 'd')
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
