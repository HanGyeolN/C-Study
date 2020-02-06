/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 16:35:43 by chekim            #+#    #+#             */
/*   Updated: 2020/02/02 14:26:45 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_left(int **board, int row, int col_size);
int		check_right(int **board, int row, int col_size);
int		check_top(int **board, int col, int row_size);
int		check_bottom(int **board, int col, int row_size);
int		is_dup(int **board, int n, int row, int col);
void	fill_all(int **board, int row, int col);

int		g_flag = 0;

int		check(int **board, int row, int col, char c)
{
	if (c == 'r')
	{
		if (check_left(board, row, 6) == 1 && check_right(board, row, 6) == 1)
			return (1);
		else
			return (0);
	}
	else if (c == 'n')
	{
		if (check_left(board, row, 6) == 1 && check_right(board, row, 6) == 1)
			fill_all(board, row + 1, 1);
	}
	else if (c == 'c')
	{
		if (check_top(board, col, 6) == 1 && check_bottom(board, col, 6) == 1)
			return (1);
		else
			return (0);
	}
	else if (c == 'o')
	{
		if (check_top(board, col, 6) == 1 && check_bottom(board, col, 6) == 1)
			fill_all(board, row, col + 1);
	}
	return (0);
}

int		check_flag(int **board, int row, int col)
{
	if (check(board, row, col, 'r') == 1 && check(board, row, col, 'c') == 1)
	{
		g_flag = 1;
		return (1);
	}
	else
		return (0);
}

void	fill_all2(int **board, int row, int col)
{
	int		i;

	i = 0;
	while (++i < 5)
	{
		if (is_dup(board, i, row, col) == 0)
		{
			board[row][col] = i;
			if (col == 4 && row == 4)
			{
				if (check_flag(board, row, col) == 1)
					return ;
			}
			else if (col == 4)
				check(board, row, col, 'n');
			else if (row == 4)
				check(board, row, col, 'o');
			else
				fill_all(board, row, col + 1);
		}
	}
	if (g_flag != 1)
		board[row][col] = 0;
}

void	fill_all(int **board, int row, int col)
{
	if (board[row][col] != 0)
	{
		if (col == 4 && row == 4)
		{
			if (check_flag(board, row, col) == 1)
				return ;
		}
		else if (col == 4)
		{
			if (check(board, row, col, 'r') == 1)
				fill_all(board, row + 1, 1);
		}
		else if (row == 4)
		{
			if (check(board, row, col, 'c') == 1)
				fill_all(board, row, col + 1);
		}
		else
			fill_all(board, row, col + 1);
	}
	else
		fill_all2(board, row, col);
}
