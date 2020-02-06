/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 20:28:58 by hna               #+#    #+#             */
/*   Updated: 2020/02/06 22:41:24 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "ft_string.h"
#define ERR_MSG_SIZE 500

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

int		ft_error(int err_num, char *path, char *pname)
{
	if (errno != 0)
	{
		ft_puterror(err_num, path, pname);
		return (1);
	}
	else
		return (0);
}

void	ft_display_file(char *path, char *pname)
{
	int		fd;
	char	buf;

	fd = open(path, O_RDONLY);
	while (read(fd, &buf, 1))
	{
		if (ft_error(errno, path, pname))
			return ;
		write(STDOUT, &buf, 1);
	}
	close(fd);
}

int		is_valid_args(int argc, char **argv)
{
	char	buf;

	if (argc == 1)
	{
		while (read(0, &buf, 1))
		{
			if (ft_error(errno, "stdin", argv[0]))
				break ;
			write(1, &buf, 1);
		}
		return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int		i;

	i = 0;
	if (is_valid_args(argc, argv) == 0)
		return (0);
	while (++i < argc)
	{
		errno = 0;
		if (ft_is_dir(argv[i]))
		{
			ft_error(errno, argv[i], argv[0]);
			continue ;
		}
		ft_display_file(argv[i], argv[0]);
	}
	return (0);
}
