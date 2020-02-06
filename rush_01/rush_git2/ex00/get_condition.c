/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_condition.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 10:15:02 by gmoon             #+#    #+#             */
/*   Updated: 2020/02/02 14:39:50 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_putstr(char *str);

int		error(void)
{
	ft_putstr("Error\n");
	return (0);
}

int		arr_size(char *str)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (str[i] != '\0')
	{
		if ('0' <= str[i] && str[i] <= '9')
			size++;
		i++;
	}
	return (size);
}

int		is_valid_input(int argc, char *str)
{
	int		i;
	int		size;

	i = 0;
	if (argc != 2)
		return (error());
	size = arr_size(str);
	if (size != 16)
		return (error());
	while (str[i])
	{
		if (!('1' <= str[i] && str[i] <= '4') && str[i] != ' ')
			return (error());
		i++;
	}
	return (1);
}

int		is_valid_output(int **board)
{
	int r;
	int c;

	r = 1;
	while (r < 5)
	{
		c = 1;
		while (c < 5)
		{
			if (board[r][c] == 0)
				return (error());
			c++;
		}
		r++;
	}
	return (1);
}

int		*get_condition(char *str)
{
	int		*int_arr;
	int		size;
	int		i;
	int		j;

	size = arr_size(str);
	int_arr = (int *)malloc(sizeof(int) * size);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			i++;
		else if ('0' <= str[i] && str[i] <= '9')
		{
			int_arr[j] = str[i] - '0';
			i++;
			j++;
		}
	}
	return (int_arr);
}
