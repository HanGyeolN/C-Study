/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:48:51 by hna               #+#    #+#             */
/*   Updated: 2020/02/11 14:52:47 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_display_file(char *fpath)
{
	int		fd;
	int		readn;
	char	buf;

	fd = open(fpath, O_RDONLY);
	readn = read(fd, &buf, 1);
	if (readn == -1 || fd == -1)
	{
		close(fd);
		return (-1);
	}
	while (read(fd, &buf, 1))
		write(1, &buf, 1);
	close(fd);
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		write(2, "File name missing.\n", 20);
	else if (argc > 2)
		write(2, "Too many arguments.\n", 21);
	else if (ft_display_file(argv[1]) == -1)
	{
		write(2, "Cannot read file.\n", 19);
		return (1);
	}
	return (-1);
}
