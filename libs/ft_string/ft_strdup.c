/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:41:48 by hna               #+#    #+#             */
/*   Updated: 2020/02/06 11:00:36 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strdup(char *src)
{
	int		size;
	char	*new;

	size = ft_strlen(src);
	new = (char *)malloc(sizeof(char) * size);
	if (new == 0)
		return (0);
	return (ft_strcpy(new, src));
}
