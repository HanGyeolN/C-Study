/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:55:47 by hna               #+#    #+#             */
/*   Updated: 2020/02/07 12:06:36 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_foreach(int *tab, int length, void (*f)(int));
int		*ft_map(int *tab, int length, int (*f)(int));
int		ft_any(char **tab, int (*f)(char *));

#include <stdio.h>
void	p(int n)
{
	printf("%d", n);
}

int		main(void)
{
	int i;
	int tab[5] = {1, 2, 3, 4, 5};

	i = -1;
	ft_foreach(tab, 5, p);

	return (0);
}
