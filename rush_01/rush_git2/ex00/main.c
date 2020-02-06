/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 09:50:02 by hna               #+#    #+#             */
/*   Updated: 2020/02/02 22:18:59 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_valid_input(int argc, char *str);
int		is_valid_output(int **board);
int		*get_condition(char *str);
int		**set_condition(int **board, int *cond, int row_size, int col_size);
int		**ft_create_board(int row_size, int col_size);
void	first_fill(int **board);
void	fill_all(int **board, int row, int col);
void	print_answer(int **board);
void	ft_print_board(int **board, int size, int size2);

int		main(int argc, char *argv[])
{
	int i;
	int	**board;
	int	*cond;

	i = 0;
	if (is_valid_input(argc, argv[1]) != 1)
		return (0);
	cond = get_condition(argv[1]);
	board = ft_create_board(6, 6);
	set_condition(board, cond, 6, 6);
	first_fill(board);
	fill_all(board, 1, 1);
	if (is_valid_output(board) != 1)
		return (0);
	print_answer(board);
	free(cond);
	while (i < 6)
	{
		free(board[i]);
		i++;
	}
	free(board);
	return (0);
}
