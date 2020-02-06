/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 10:19:10 by hna               #+#    #+#             */
/*   Updated: 2020/01/26 15:31:39 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

int main(void)
{
	char str[10];
	unsigned int ret;
	int i;

	i = 6;
	ret = ft_strlcpy(str, "abcdef", i);
	printf("expect: %s", "abcdef");
	printf("\n");
	printf("result: %s, ret: %d\n", str, ret);

	ret = strlcpy(str, "abcdef", i);
	printf("origin: %s, ret: %d\n", str, ret);
	return (0);
}
