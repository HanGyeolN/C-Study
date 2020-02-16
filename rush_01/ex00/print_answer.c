/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_answer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 10:15:50 by gmoon             #+#    #+#             */
/*   Updated: 2020/02/02 10:15:53 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	ft_putnbr(int nbr);

void	print_answer(int **board)
{
	int i;
	int j;

	i = 0;
	while (i <= 3)
	{
		j = 0;
		while (j <= 3)
		{
			ft_putnbr(board[i + 1][j + 1]);
			if (j < 3)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
