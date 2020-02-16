/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 21:03:41 by hna               #+#    #+#             */
/*   Updated: 2020/02/06 11:02:45 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int		get_total_strlen(int size, char **strs, char *sep)
{
	int i;
	int total_len;
	int sep_len;

	i = 0;
	total_len = 0;
	sep_len = ft_strlen(sep);
	total_len = sep_len * (size - 1);
	while (i < size)
	{
		total_len += ft_strlen(strs[i]);
		i++;
	}
	return (total_len + 1);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		total_len;
	int		i;
	char	*dest;

	i = 0;
	dest = 0;
	if (size == 0)
	{
		dest = (char *)malloc(sizeof(char) * 1);
		return (dest);
	}
	total_len = get_total_strlen(size, strs, sep);
	dest = (char *)malloc(sizeof(char) * total_len);
	dest[0] = '\0';
	while (i < size)
	{
		ft_strcat(dest, strs[i]);
		if (i != size - 1)
			ft_strcat(dest, sep);
		i++;
	}
	return (dest);
}
