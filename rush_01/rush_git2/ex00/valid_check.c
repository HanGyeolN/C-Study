/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 18:12:41 by hna               #+#    #+#             */
/*   Updated: 2020/02/02 12:05:38 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_left(int **board, int row, int col_size)
{
	int	c;
	int	max;
	int	count;
	int	left_see;

	c = 1;
	max = 0;
	count = 0;
	left_see = board[row][0];
	while (c < col_size - 1)
	{
		if (max < board[row][c])
		{
			max = board[row][c];
			count++;
		}
		c++;
	}
	if (count == left_see)
		return (1);
	else
		return (0);
}

int		check_right(int **board, int row, int col_size)
{
	int	c;
	int	max;
	int	count;
	int	right_see;

	c = col_size - 2;
	max = 0;
	count = 0;
	right_see = board[row][col_size - 1];
	while (c > 0)
	{
		if (max < board[row][c])
		{
			max = board[row][c];
			count++;
		}
		c--;
	}
	if (count == right_see)
		return (1);
	else
		return (0);
}

int		check_top(int **board, int col, int row_size)
{
	int	r;
	int	max;
	int	count;
	int	top_see;

	r = 1;
	max = 0;
	count = 0;
	top_see = board[0][col];
	while (r < row_size - 1)
	{
		if (max < board[r][col])
		{
			max = board[r][col];
			count++;
		}
		r++;
	}
	if (count == top_see)
		return (1);
	else
		return (0);
}

int		check_bottom(int **board, int col, int row_size)
{
	int	r;
	int	max;
	int	count;
	int	bottom_see;

	r = row_size - 2;
	max = 0;
	count = 0;
	bottom_see = board[row_size - 1][col];
	while (r > 0)
	{
		if (max < board[r][col])
		{
			max = board[r][col];
			count++;
		}
		r--;
	}
	if (count == bottom_see)
		return (1);
	else
		return (0);
}

int		is_dup(int **board, int n, int row, int col)
{
	int r;
	int c;

	r = 1;
	c = 1;
	while (r < 5)
	{
		if (n == board[r][col])
			return (1);
		r++;
	}
	while (c < 5)
	{
		if (n == board[row][c])
			return (1);
		c++;
	}
	return (0);
}
