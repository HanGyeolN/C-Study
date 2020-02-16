/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:50:24 by hna               #+#    #+#             */
/*   Updated: 2020/02/06 20:23:56 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft.h"

int		ft_is_dir(char *target)
{
	int		fd;
	char	test;

	errno = 0;
	fd = open(target, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("error in ft_is_dir\n");
		return (-1);
	}
	else
	{
		read(fd, &test, 1);
		if (errno)
		{
			close(fd);
			return (1);
		}
		close(fd);
		return (0);
	}
}
