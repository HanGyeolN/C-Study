/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 14:21:36 by hna               #+#    #+#             */
/*   Updated: 2020/02/02 22:52:43 by hna              ###   ########.fr       */
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

int				is_valid(char *base)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (base[0] == '\0')
		return (0);
	while (base[i])
	{
		if (base[i] == ' ' || base[i] == '+' || base[i] == '-' ||
				(9 <= base[i] && base[i] <= 13))
			return (0);
		if (is_in(base[i], &base[i + 1]) != -1)
			return (0);
		i++;
	}
	return (1);
}

int				ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
