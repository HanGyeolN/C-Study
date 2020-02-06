/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 21:03:41 by hna               #+#    #+#             */
/*   Updated: 2020/02/02 21:40:30 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int dest_len;

	i = 0;
	dest_len = ft_strlen(dest);
	while (src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

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
	while (i < size - 1)
	{
		ft_strcat(dest, strs[i]);
		ft_strcat(dest, sep);
		i++;
	}
	ft_strcat(dest, strs[i]);
	return (dest);
}
