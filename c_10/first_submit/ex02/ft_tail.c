/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:50:27 by hna               #+#    #+#             */
/*   Updated: 2020/02/06 22:58:40 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft.h"
#define ERR_MSG_SIZE 500
#define STDIN 0
#define STDOUT 1
#define STDERR 2

#include <stdio.h>

void	ft_puterror(int err_num, char *pname)
{
	char	buf[ERR_MSG_SIZE];

	ft_init_str(buf, ERR_MSG_SIZE);
	ft_strcat(buf, basename(pname));
	ft_strcat(buf, ": ");
	ft_strcat(buf, strerror(err_num));
	ft_strcat(buf, "\n");
	write(STDERR, buf, ERR_MSG_SIZE);
}

int		ft_tail_error(int err_num, char *pname)
{
	if (err_num)
	{
		ft_puterror(err_num, pname);
		return (1);
	}
	else
		return (0);
}

int		ft_error(int err_num)
{
	if (err_num)
	{
		ft_putstr_err(strerror(err_num));
		ft_putstr_err("\n");
		return (1);
	}
	else
		return (0);
}

void	tail(char *fname, int tail_num)
{
	int		j;
	int		size;
	char	*buf;
	int		fd;

	j = -1;
	if (ft_is_dir(fname) == 1 || tail_num == 0)
		return ;
	fd = open(fname, O_RDONLY);
	size = ft_get_filesize(fname);
	buf = (char *)malloc(sizeof(char) * (size + 1));
	ft_init_str(buf, size + 1);
	while (++j < size - tail_num)
		read(fd, &buf[0], 1);
	read(fd, buf, tail_num);
	ft_putstr(buf);
	free(buf);
	close(fd);
}

void	ft_print_fileinfo(char *fname)
{
	char	fileinfo[500];

	ft_init_str(fileinfo, 500);
	ft_strcat(fileinfo, "==> ");
	ft_strcat(fileinfo, fname);
	ft_strcat(fileinfo, " <==");
	ft_strcat(fileinfo, "\n");
	ft_putstr(fileinfo);
}

int		is_valid_args(int argc, char **argv)
{
	char	buf[500];

	printf("argc: %d\n", argc);
	ft_init_str(buf, 500);
	if (argc == 3)
	{
		if (ft_tail_error(errno, argv[0]))
			return (0);
		tail(argv[i], tail_num);
		if (argc > 4 && i < argc - 1)
			ft_putstr("\n");
	}
	if (!ft_str_is_numeric(argv[2]))
	{
		ft_strcat(buf, basename(argv[0]));
		ft_strcat(buf, ": illegal offset -- ");
		ft_strcat(buf, argv[2]);
		ft_strcat(buf, "\n");
		ft_putstr_err(buf);
		return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int		i;
	int		tail_num;

	if (is_valid_args(argc, argv) == 0)
		return (0);
	i = 2;
	tail_num = ft_atoi(argv[2]);
	while (++i < argc)
	{
		errno = 0;
		if (argc > 4)
			ft_print_fileinfo(argv[i]);
		if (ft_tail_error(errno, argv[0]))
			continue ;
		tail(argv[i], tail_num);
		if (argc > 4 && i < argc - 1)
			ft_putstr("\n");
	}
	return (0);
}
