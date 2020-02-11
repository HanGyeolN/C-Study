/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 10:55:26 by hna               #+#    #+#             */
/*   Updated: 2020/02/10 21:57:10 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_tail.h"

void	ft_puterror(int err_num, char *path, char *pname)
{
	char	buf[ERR_MSG_SIZE];
	char	*err_msg;

	ft_init_str(buf, ERR_MSG_SIZE);
	err_msg = strerror(err_num);
	ft_strcat(buf, basename(pname));
	ft_strcat(buf, ": ");
	ft_strcat(buf, path);
	ft_strcat(buf, ": ");
	ft_strcat(buf, err_msg);
	ft_strcat(buf, "\n");
	write(STDERR, buf, ERR_MSG_SIZE);
}

/*
** open, read, error check and print last nth str
** using file info struct
*/

void	ft_tail_re(int ntail, char *pname)
{
	int		idx;
	int		readn;
	char	buf[MAX_BUF_SIZE];
	char	result_buf[MAX_BUF_SIZE];

	readn = read(0, buf, MAX_BUF_SIZE);
	idx = readn;
	if (readn != -1 && readn != 0)
		ft_strcpy(result_buf, buf);
	else
	{
		ft_puterror(errno, "stdin", pname);
		return ;
	}
	while (readn)
	{
		readn = read(0, buf, MAX_BUF_SIZE);
		if (readn)
			ft_strcat(result_buf, buf);
		idx += readn;
	}
	idx = idx - ntail;
	if (idx < 0)
		idx = 0;
	ft_putstr(result_buf + idx);
}

int		print_if_open_error(t_fileinfo *finfo)
{
	if (finfo->errno_open != 0)
	{
		ft_putstr(basename(finfo->pname));
		ft_putstr(": ");
		ft_putstr(finfo->filepath);
		ft_putstr(": ");
		ft_putstr(strerror(finfo->errno_open));
		ft_putstr("\n");
		return (1);
	}
	return (0);
}

void	ft_multi_tail(t_fileinfo *finfo, int ntail, int flag)
{
	int		idx;
	int		fd;
	char	*buf;

	if (print_if_open_error(finfo))
		return ;
	if (flag == 1)
		ft_putstr("\n==> ");
	else
		ft_putstr("==> ");
	ft_putstr(finfo->filepath);
	ft_putstr(" <==\n");
	if (finfo->errno_read != 0)
		return ;
	fd = open(finfo->filepath, O_RDONLY);
	buf = (char *)malloc(sizeof(char) * (finfo->size + 1));
	if (buf == 0)
		return ;
	read(fd, buf, finfo->size);
	buf[finfo->size] = '\0';
	idx = finfo->size - ntail;
	if (idx < 0)
		idx = 0;
	ft_putstr(buf + idx);
	free(buf);
}

void	ft_tail(t_fileinfo *finfo, int ntail)
{
	int		idx;
	int		fd;
	char	*buf;

	if (print_if_open_error(finfo))
		return ;
	if (finfo->errno_read != 0)
		return ;
	fd = open(finfo->filepath, O_RDONLY);
	buf = (char *)malloc(sizeof(char) * (finfo->size + 1));
	if (buf == 0)
		return ;
	read(fd, buf, finfo->size);
	buf[finfo->size] = '\0';
	idx = finfo->size - ntail;
	if (idx < 0)
		idx = 0;
	ft_putstr(buf + idx);
	free(buf);
}
