/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:27:37 by hna               #+#    #+#             */
/*   Updated: 2020/02/03 21:57:46 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strncpy(char *dest, const char *src, int n)
{
	int i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
#include <stdio.h>
#include <string.h>
int main(int argc, char **argv)
{
	int	i;
	char s1[10];
	char s2[10];

	i = 0;

	while (i < 10)
	{
		printf("=== %d ===\n", i);
		ft_strncpy(s1, "abcd", i);
		strncpy(s2, "abcd", i);
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
