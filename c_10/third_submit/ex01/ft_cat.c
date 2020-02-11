/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 20:28:58 by hna               #+#    #+#             */
/*   Updated: 2020/02/10 22:06:11 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"
#include "ft_string.h"
#define ERR_MSG_SIZE 500

int		print_if_error(t_fileinfo *finfo)
{
	if (finfo->errno_open != 0 || finfo->errno_read != 0)
	{
		ft_putstr(basename(finfo->pname));
		ft_putstr(": ");
		ft_putstr(finfo->filepath);
		ft_putstr(": ");
		if (finfo->errno_open != 0)
			ft_putstr(strerror(finfo->errno_open));
		else
			ft_putstr(strerror(finfo->errno_read));
		ft_putstr("\n");
		return (1);
	}
	return (0);
}

void	ft_cat(t_fileinfo *finfo)
{
	int		fd;
	char	buf;

	if (print_if_error(finfo))
		return ;
	fd = open(finfo->filepath, O_RDONLY);
	while (read(fd, &buf, 1))
		write(STDOUT, &buf, 1);
	close(fd);
}

void	ft_cat_re(char *pname)
{
	char	buf;

	errno = 0;
	while (read(0, &buf, 1))
	{
		if (errno)
		{
			ft_putstr(basename(pname));
			ft_putstr(": stdin: ");
			ft_putstr(strerror(errno));
			ft_putstr("\n");
			return ;
		}
		write(1, &buf, 1);
	}
}

int		main(int argc, char **argv)
{
	t_fileinfo	*finfo;
	int			i;

	i = 0;
	if (argc == 1)
		ft_cat_re(argv[0]);
	else if (argc > 1)
	{
		while (++i < argc)
		{
			finfo = get_fileinfo(argv[i], argv[0]);
			ft_cat(finfo);
		}
	}
	return (0);
}
