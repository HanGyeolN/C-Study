/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 12:27:42 by hna               #+#    #+#             */
/*   Updated: 2020/02/07 13:25:58 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_intcmp(int n1, int n2)
{
	return (n1 - n2);
}

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	f = ft_intcmp;
	if (length < 3)
		return (1);
	while (i < length - 1)
	{
		if (ft_intcmp(tab[i], tab[i + 1]) < 0 && flag == 0)
			flag = 1;
		if (ft_intcmp(tab[i], tab[i + 1]) > 0 && flag == 0)
			flag = -1;
		if (ft_intcmp(tab[i], tab[i + 1]) > 0 && flag == 1)
			return (0);
		if (ft_intcmp(tab[i], tab[i + 1]) < 0 && flag == -1)
			return (0);
		i++;
	}
	return (1);
}
