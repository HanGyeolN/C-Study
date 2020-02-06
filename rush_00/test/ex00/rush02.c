/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:24:53 by sanam             #+#    #+#             */
/*   Updated: 2020/01/27 13:51:13 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char a);

void	ft_first(int n)
{
	int c;

	c = 1;
	ft_putchar('A');
	while (++c < n)
		ft_putchar('B');
	if (n > 1)
		ft_putchar('A');
}

void	ft_last(int n)
{
	int c;

	c = 1;
	ft_putchar('C');
	while (++c < n)
		ft_putchar('B');
	if (n > 1)
		ft_putchar('C');
}

void	ft_putbspace(int n)
{
	int c;

	c = 1;
	ft_putchar('B');
	while (++c < n)
		ft_putchar(' ');
	if (n > 1)
		ft_putchar('B');
}

void	rush(int x, int y)
{
	int i;

	i = 1;
	while (i <= y)
	{
		if (i == 1)
		{
			ft_first(x);
		}
		else if (i == y)
		{
			ft_last(x);
		}
		else
		{
			ft_putbspace(x);
		}
		ft_putchar('\n');
		i++;
	}
}
