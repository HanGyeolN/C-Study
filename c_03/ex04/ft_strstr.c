/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:19:05 by hna               #+#    #+#             */
/*   Updated: 2020/01/27 18:56:29 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i < n)
	{
		if (s1[i] == '\0' || s2[i] == '\0')
			return (s1[i] - s2[i]);
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

unsigned int	ft_strlen(char *src)
{
	unsigned int len;

	len = 0;
	while (src[len] != '\0')
		len++;
	return (len);
}

char			*ft_strstr(char *str, char *to_find)
{
	unsigned int	i;
	unsigned int	find_len;
	unsigned int	str_len;
	int				res;

	i = 0;
	find_len = ft_strlen(to_find);
	str_len = ft_strlen(str);
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0' && i <= find_len - str_len)
	{
		res = ft_strncmp(str + i, to_find, find_len);
		if (res == 0)
			return (str + i);
		i++;
	}
	return (0);
}
