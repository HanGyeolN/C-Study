/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:48:51 by hna               #+#    #+#             */
/*   Updated: 2020/02/05 20:15:14 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdio.h>

int		is_valid_argc(int argc)
{
	if (argc <= 1)
	{
		write(2, "File name missing.\n", 20);
		return (0);
	}
	else if (argc > 2)
	{
		write(2, "Too many arguments.\n", 21);
		return (0);
	}
	else
		return (1);
}

int		is_valid_fd(int fd)
{
	if (fd == -1)
	{
		write(2, "Cannot read file.\n", 19);
		return (0);
	}
	else
		return (1);
}

void	ft_display_file(int argc, char **argv)
{
	int		fd;
	char	buf;

	if (is_valid_argc(argc) == 0)
		return ;
	fd = open(argv[1], O_RDONLY);
	if (is_valid_fd(fd) == 0)
		return ;
	while (read(fd, &buf, 1))
		write(1, &buf, 1);
	close(fd);
}
