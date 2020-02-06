/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:06:49 by hna               #+#    #+#             */
/*   Updated: 2020/02/03 20:10:43 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char				*ft_strdup(char *src)
{
	int		i;
	int		str_len;
	char	*new_str;

	i = 0;
	str_len = ft_strlen(src);
	new_str = (char *)malloc(sizeof(char) * (str_len + 1));
	if (new_str == 0)
		return (0);
	while (src[i])
	{
		new_str[i] = src[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	int			str_len;
	t_stock_str	*strs;

	i = 0;
	strs = malloc(sizeof(t_stock_str) * (ac + 1));
	if (strs == 0)
		return (0);
	while (i < ac)
	{
		str_len = ft_strlen(av[i]);
		strs[i].size = str_len;
		strs[i].str = av[i];
		strs[i].copy = ft_strdup(av[i]);
		i++;
	}
	strs[i].str = 0;
	return (strs);
}
