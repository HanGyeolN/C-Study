/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 14:21:36 by hna               #+#    #+#             */
/*   Updated: 2020/02/03 12:39:01 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				is_in(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int				ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int				is_valid(char *base)
{
	int i;
	int j;
	int base_len;

	i = 0;
	j = 0;
	if (!base)
		return (0);
	base_len = ft_strlen(base);
	while (base[i])
	{
		if (base[i] == ' ' || base[i] == '+' || base[i] == '-' ||
				(9 <= base[i] && base[i] <= 13))
			return (0);
		j = i + 1;
		while (j < base_len)
		{
			if (is_in(base[i], base[j]) != -1)
			return (0);
		}
		i++;
	}
	return (1);
}
