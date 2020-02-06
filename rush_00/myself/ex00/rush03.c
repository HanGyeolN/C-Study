/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 20:02:11 by hna               #+#    #+#             */
/*   Updated: 2020/01/27 21:23:38 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_putchar(char c);

void print_first(int n)
{
	int i;

	i = 1;
	ft_putchar('A');
	while (++i < n)
		ft_putchar('B');
	if (n > 1)
		ft_putchar('C');
}

void print_bspace(int n)
{
	int i;

	i = 1;
	ft_putchar('B');
	while (++i <n)
		ft_putchar(' ');
	if (n > 1)
		ft_putchar('B');
}

void rush(int a, int b)
{
	int i;

	i = 1;
	
	while (i <= b)
	{
		if (i == 1 || i == b)
			print_first(a);
		else
			print_bspace(a);
		ft_putchar('\n');
		i++;
	}
}

