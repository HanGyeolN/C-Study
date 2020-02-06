/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_board.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 22:30:27 by hna               #+#    #+#             */
/*   Updated: 2020/02/02 11:05:20 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_putchar(char c);
void	ft_putnbr(int nb);

int		**ft_print_board(int **board, int row_size, int col_size)
{
	int r;
	int c;

	r = 0;
	c = 0;
	while (r < row_size)
	{
		c = 0;
		while (c < col_size)
		{
			ft_putnbr(board[r][c]);
			if (c != col_size - 1)
				ft_putchar(' ');
			c++;
		}
		ft_putchar('\n');
		r++;
	}
	return (board);
}

int		**ft_create_board(int row_size, int col_size)
{
	int **board;
	int r;
	int c;

	r = 0;
	board = (int **)malloc(sizeof(int *) * row_size);
	while (r < row_size)
	{
		c = 0;
		board[r] = (int *)malloc(sizeof(int) * col_size);
		while (c < col_size)
		{
			board[r][c] = 0;
			c++;
		}
		r++;
	}
	return (board);
}

int		**set_condition(int **board, int *cond, int row_size, int col_size)
{
	int i;
	int j;

	i = 0;
	j = -1;
	while (++j < col_size - 2)
	{
		board[0][j + 1] = cond[i];
		i++;
	}
	j = -1;
	while (++j < col_size - 2)
	{
		board[row_size - 1][j + 1] = cond[i];
		i++;
	}
	j = -1;
	while (++j < row_size - 2)
	{
		board[j + 1][0] = cond[i];
		board[j + 1][col_size - 1] = cond[i + row_size - 2];
		i++;
	}
	return (board);
}
