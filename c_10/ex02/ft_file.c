/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 22:47:09 by hna               #+#    #+#             */
/*   Updated: 2020/02/10 21:01:30 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_tail.h"

void		init_fileinfo(t_fileinfo *fileinfo)
{
	fileinfo->fd = -1;
	fileinfo->size = 0;
	fileinfo->errno_open = 0;
	fileinfo->errno_read = 0;
	fileinfo->type = '\0';
	ft_strcpy(fileinfo->filepath, "");
}

int			ft_error(int err_num)
{
	if (err_num)
		return (1);
	else
		return (0);
}

void		set_fileinfo(t_fileinfo *fileinfo, char *fpath)
{
	int		fd;
	int		size;
	char	buf;

	size = 0;
	errno = 0;
	fd = open(fpath, O_RDONLY);
	if (ft_error(errno))
		fileinfo->errno_open = errno;
	while (read(fd, &buf, 1))
	{
		if (ft_error(errno))
		{
			fileinfo->errno_read = errno;
			if (errno == 21)
				fileinfo->type = 'd';
			break ;
		}
		size++;
	}
	if (!errno)
		fileinfo->type = 'f';
	fileinfo->size = size;
	ft_strcat(fileinfo->filepath, fpath);
	close(fd);
}

t_fileinfo	*get_fileinfo(char *fpath, char *pname)
{
	t_fileinfo	*finfo;

	finfo = (t_fileinfo *)malloc(sizeof(t_fileinfo) * 1);
	init_fileinfo(finfo);
	set_fileinfo(finfo, fpath);
	ft_strcpy(finfo->pname, pname);
	return (finfo);
}

void		show_fileinfo(t_fileinfo *finfo)
{
	ft_putstr("fd: ");
	ft_putnbr(finfo->fd);
	ft_putstr("\nsize: ");
	ft_putnbr(finfo->size);
	ft_putstr("\nerrno_open: ");
	ft_putnbr(finfo->errno_open);
	ft_putstr("\nerrno_read: ");
	ft_putnbr(finfo->errno_read);
	ft_putstr("\nopen_path: ");
	ft_putstr(finfo->filepath);
	ft_putstr("\nprogram_name: ");
	ft_putstr(finfo->pname);
	ft_putchar('\n');
}
