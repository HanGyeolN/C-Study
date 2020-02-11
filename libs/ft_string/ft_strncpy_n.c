/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 13:50:45 by hna               #+#    #+#             */
/*   Updated: 2020/02/09 13:50:56 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strncpy_n(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	char			*new_str;

	i = 0;
	while (i < n)
	{
		if (src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		else
		{
			while (i < n)
			{
				dest[i] = '\0';
				i++;
			}
		}
	}
	dest[i] = '\0';
	new_str = dest;
	return (new_str);
}
