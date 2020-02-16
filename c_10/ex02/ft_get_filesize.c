/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_filesize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 19:59:19 by hna               #+#    #+#             */
/*   Updated: 2020/02/06 20:02:40 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft.h"

int		ft_get_filesize(char *fpath)
{
	int		fd;
	int		len;
	char	buf;

	len = 0;
	fd = open(fpath, O_RDONLY);
	while (read(fd, &buf, 1))
		len++;
	return (len);
}
