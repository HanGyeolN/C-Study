/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:27:37 by hna               #+#    #+#             */
/*   Updated: 2020/01/26 18:51:07 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	get_length(char *src)
{
	unsigned int	length;

	length = 0;
	while (src[length] != '\0')
		length++;
	return (length);
}

char			*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	unsigned int	src_len;

	i = 0;
	src_len = get_length(src);
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	if (src_len < n)
	{
		while (i < n)
		{
			dest[i] = '\0';
			i++;
		}
	}
	return (dest);
}
