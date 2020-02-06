/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 21:40:36 by hna               #+#    #+#             */
/*   Updated: 2020/01/27 21:50:43 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putfirst(int w)
{
	int i;

	i = 1;
	ft_putchar('A');
	while (++i < w)
		ft_putchar('B');
	if (w > 1)
		ft_putchar('C');
}
void	ft_putbspace(int w)
{
	int i;

	i = 1;
	ft_putchar('B');
	while (++i < w)
		ft_putchar(' ');
	if (w > 1)
		ft_putchar('B');
}

void	ft_putlast(int w)
{
	int i;

	i = 1;
	ft_putchar('C');
	while (++i < w)
		ft_putchar(' ');
	if (w > 1)
		ft_putchar('A');
}

void	rush(int w, int h)
{
	int r;

	r = 1;
	if (r <= 0 || h <= 0)
		return ;
	while (r <= h)
	{
		if (r == 1)
			ft_putfirst(w);
		else if (r == h)
			ft_putlast(w);
		else
			ft_putbspace(w);
		ft_putchar('\n');
		r++;
	}
}
