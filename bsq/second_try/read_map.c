/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:10:09 by hna               #+#    #+#             */
/*   Updated: 2020/02/11 18:10:17 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_putstr_err(char *str)
{
	while (*str)
		write(2, str++, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putnbr(int num)
{
	if (num < 0)
	{
		write(1, &"-", 1);
		num = -num;
	}
	if (num > 9)
		ft_putnbr(num / 10);
	write(1, &"0123456789"[num % 10], 1);
}

int		ft_atoi(char *str)
{
	int		res;
	int		sign;

	res = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1 * sign;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0') * sign;
		str++;
	}
	return (res);
}

void	read_first_line(char *fpath, t_map_info *minfo)
{
	int		i;
	int		fd;
	char	buf[BUF_SIZE];

	ft_putstr("read_first_line function start\n"); //
	i = 0;
	fd = open(fpath, O_RDONLY);
	read(fd, buf, BUF_SIZE);
	while (buf[i] != '\n')
		i++;
	minfo->full_char = buf[i - 1];
	minfo->obstacle_char = buf[i - 2];
	minfo->empty_char = buf[i - 3];
	buf[i - 3] = '\0';
	minfo->nrow = ft_atoi(buf);
	close(fd);
}

int			print_if_error(int error_num)
{
	if (error_num == 0)
		return (0);
	ft_putstr_err(strerror(error_num));
	ft_putstr_err("\n");
	return (1);
}

t_map_info	*get_map_info(char *fpath)
{
	int			fd;
	int			ncol;
	char		skip;
	t_map_info	*map_info;

	ncol = 0;
	map_info = malloc(1 * sizeof(t_map_info));
	read_first_line(fpath, map_info);
	fd = open(fpath, O_RDONLY);
	if (print_if_error(errno))
		return (0);	
	read(fd, &skip, 1);
	if (print_if_error(errno))
		return (0);
	while (skip != '\n')
		read(fd, &skip, 1);
	read(fd, &skip, 1);
	while (skip != '\n')
	{
		read(fd, &skip, 1);
		ncol++;
	}
	map_info->ncol = ncol;
	return (map_info);
}

int		get_filesize(char *fpath)
{
	int		fd;
	int		size;
	char	buf;

	size = 0;
	fd = open(fpath, O_RDONLY);
	while (read(fd, &buf, 1))
		size++;
	close(fd);
	return (size);
}

int		**malloc_map(t_map_info *minfo)
{
	int		r;
	int		**map;

	r = 0;
	map = (int **)malloc(sizeof(int *) * minfo->nrow);
	while (r < minfo->nrow)
	{
		map[r] = (int *)malloc(sizeof(int) * minfo->ncol);
		r++;
	}
	return (map);
}

void	put_data(int **map, char *buf, t_map_info *minfo)
{
	int		i;
	int		r;
	int		c;

	i = 0;
	r = -1;
//	ft_putstr("a\n");
//	ft_putstr(buf);
	while (buf[i] != '\n')
		i++;
//	ft_putstr(&buf[i]);
	i++;
//	ft_putchar(minfo->empty_char);
//	ft_putchar(minfo->obstacle_char);
	while (++r < minfo->nrow)
	{
		c = -1;
		while (++c < minfo->ncol)
		{
//			ft_putchar(buf[i]);
//			ft_putchar('\n');
			while (buf[i] != minfo->obstacle_char && buf[i] != minfo->empty_char)
				i++;
			if (buf[i] == minfo->obstacle_char)
			{
				i++;
				map[r][c] = 0;
			}
			else if (buf[i] == minfo->empty_char)
			{
				i++;
				map[r][c] = 1;
			}
		}
//		ft_putstr(&buf[i]);
	}
}	

int		**read_map(t_map_info *minfo, char *fpath)
{
	int		fd;
	int		size;
	int		**map;
	char	*buf;

//	ft_putstr("malloc_map function start\n");
	map = malloc_map(minfo);
//	ft_putstr("get_fileszie function start\n");
	size = get_filesize(fpath);
	buf = (char *)malloc(sizeof(char) * size);
	fd = open(fpath, O_RDONLY);
	read(fd, buf, size);
	put_data(map, buf, minfo);
	return (map);
}

void	show_map(int **map, t_map_info *minfo)
{
	int		r;
	int		c;

	r = 0;
	while (r < minfo->nrow)
	{
		c = 0;
		while (c < minfo->ncol)
		{
			ft_putnbr(map[r][c]);
			ft_putstr("  ");
			c++;
		}
		ft_putstr("\n");
		r++;
	}
}

void	ft_min(int **map, int r, int c)
{
	int min;

	min = map[r - 1][c - 1];
	if (min > map[r][c - 1])
		min = map[r][c - 1];
	if (min > map[r - 1][c])
		min = map[r - 1][c];
	map[r][c] = min + 1;
}

int		**bsq(int **map, t_map_info *minfo)
{
	int		r;
	int		c;

	r = 1;
	c = 1;
	while (r < minfo->nrow)
	{
		c = 1;
		while (c < minfo->ncol)
		{
			if (map[r][c] != 0)
				ft_min(map, r, c);
			c++;
		}
		r++;
	}
	return (map);
}

int	main(int argc, char **argv)
{
	t_map_info	*minfo;
	int			**map;
	int			r;
	
	r = -1;
	if (argc)
	{
		minfo = get_map_info(argv[1]);
		map = read_map(minfo, argv[1]);
		show_map(map, minfo);
		bsq(map, minfo);
		ft_putstr("======================================================\n");
		show_map(map, minfo);
	}
	while (++r < minfo->nrow)
		free(map[r]);
	free(map);
	free(minfo);
	return (0);
}
