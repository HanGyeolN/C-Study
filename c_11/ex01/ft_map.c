/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:52:50 by hna               #+#    #+#             */
/*   Updated: 2020/02/07 11:55:11 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*ret_arr;

	i = 0;
	ret_arr = (int *)malloc(sizeof(int) * length);
	while (i < length)
	{
		ret_arr[i] = f(tab[i]);
		i++;
	}
	return (ret_arr);
}
