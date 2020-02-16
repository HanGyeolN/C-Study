/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:27:37 by hna               #+#    #+#             */
/*   Updated: 2020/02/03 21:51:25 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
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
	new_str = dest;
	return (new_str);
}
#include <stdio.h>
#include <string.h>
int main(int argc, char **argv)
{
	int	i;
	char *s1;
	char *s2;

	i = 0;

	while (i < 10)
	{
		printf("=== %d ===\n", i);
		s1 = ft_strncpy(s1, "abcd", i);
		s2 = strncpy(s2, "abcd", i);
		printf("%s\n", s1);
		printf("%s\n", s2);
		i++;
	}

	while (i > 0)
	{
		printf("=== %d ===\n", i);
		ft_strncpy(s1, "abcd", i);
		strncpy(s2, "abcd", i);
		printf("%s\n", s1);
		printf("%s\n", s2);
		i--;
	}
	return (0);
}
