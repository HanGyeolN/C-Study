/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 18:28:04 by hna               #+#    #+#             */
/*   Updated: 2020/02/02 16:29:14 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int				*arr;
	long long int	size;
	long long int	i;

	i = 0;
	arr = 0;
	if (min >= max)
		return (arr);
	size = max - min;
	arr = (int *)malloc(sizeof(int) * size);
	while (min < max)
	{
		arr[i] = min;
		min++;
		i++;
	}
	return (arr);
}
