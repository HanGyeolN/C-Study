/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 10:19:44 by hna               #+#    #+#             */
/*   Updated: 2020/01/30 10:40:51 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*get_factors(int nb, int *factor_arr)
{
	int i;
	int div;
	int mod;
	int n;

	n = 0;
	i = 1;
	while (nb > 1)
	{
		i++;
		div = nb / i;
		mod = nb % i;
		if (mod == 0)
		{
			factor_arr[n] = i;
			nb = nb / i;
			i = 1;
			n++;
		}
	}
	return (factor_arr);
}

int	ft_sqrt(int nb)
{
	int i;
	int ret;
	int factors[50];

	if (nb <= 0)
		return (0);
	else if (nb == 1)
		return (1);
	i = -1;
	while (++i < 50)
		factors[i] = 0;
	get_factors(nb, factors);
	i = 0;
	ret = 1;
	while (factors[i] != 0)
	{
		if (factors[i] != factors[i + 1])
			return (0);
		else
		{
			ret = ret * factors[i];
			i = i + 2;
		}
	}
	return (ret);
}
