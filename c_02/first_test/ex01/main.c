/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 11:45:29 by hna               #+#    #+#             */
/*   Updated: 2020/01/26 18:50:13 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);

int		main(void)
{
	char s1[10] = "bcdefg";
	char s2[10] = "bcdefg";

	ft_strncpy(s1, "hfi", 1);
	printf("my: %s\n", s1);
	strncpy(s2, "hfi", 1);
	printf("cp: %s\n", s2);
	return (0);
}
