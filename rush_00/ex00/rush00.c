/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 17:13:31 by hna               #+#    #+#             */
/*   Updated: 2020/01/26 17:13:35 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char a);

void	ft_putfirst(int n)
{
	int c;

	c = 1;
	ft_putchar('o');
	while (++c < n)
		ft_putchar('-');
	if (n > 1)
		ft_putchar('o');
}

void	ft_putlast(int n)
{
	int c;

	c = 1;
	ft_putchar('o');
	while (++c < n)
		ft_putchar('-');
	if (n > 1)
		ft_putchar('o');
}

void	ft_putbspace(int n)
{
	int c;

	c = 1;
	ft_putchar('|');
	while (++c < n)
		ft_putchar(' ');
	if (n > 1)
		ft_putchar('|');
}

void	rush(int x, int y)
{
	int i;

	i = 1;
	while (i <= y)
	{
		if (i == 1)
			ft_putfirst(x);
		else if (i == y)
			ft_putlast(x);
		else
			ft_putbspace(x);
		ft_putchar('\n');
		i++;
	}
}
