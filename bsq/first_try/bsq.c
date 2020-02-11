/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:04:21 by hna               #+#    #+#             */
/*   Updated: 2020/02/10 19:00:49 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "ft_string.h"

char	**ft_split(char *str, char *charset);
#define SIZE 5000

int		g_nrow;
int		g_ncol;

char	*ft_strncpy_n(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		else
		{
			while (i < n)
			{
				dest[i] = '\0';
				i++;
			}
		}
	}
	dest[i] = '\0';
	return (dest);
}

char	**make_map(char *path)
{
	int		i;
	int		fd;
	char	buf[SIZE];
	char	skip;

	ft_putstr("make_map function start\n");
	i = 0;
	fd = open(path, O_RDONLY);
	read(fd, &skip, 1);
	while (skip != '\n')
		read(fd, &skip, 1);

	// Allocate map and put data
	read(fd, buf, SIZE);
	return (ft_split(buf, "\n"));
}

char	**get_map(char *path)
{
	int		fd;
	char	skip;
	int		nrow;
	int		ncol;
	char	**map;

	ft_putstr("get_map function start\n");
	nrow = 0;
	ncol = 0;
	fd = open(path, O_RDONLY);
	read(fd, &skip, 1);
	while (skip != '\n') // skip first line
		read(fd, &skip, 1);
	// get row, col size
	while (skip != '\0' && read(fd, &skip, 1))
	{
		while (skip != '\n')
		{
			read(fd, &skip, 1);
			ncol++;
		}
		nrow++;
	}
	close(fd);
	ncol = ncol / 20;
//	printf("nrow: %d, ncol: %d\n", nrow, ncol); //
	g_nrow = nrow;
	g_ncol = ncol;
	map = make_map(path);
	return (map);
}

void	print_map(char **map)
{
	int		r;
	
	ft_putstr("print map start\n");
	r = 0;
	while (r < 20)
	{
		ft_putstr(map[r]);
		ft_putstr("\n");
		r++;
	}
}

void	bsq(char **map)
{
	int		r;
	int		c;

	r = 0;
	c = 0;
	map
	while (r < g_nrow)
	{
		while (c < g_ncol)
		{
			


int		main(int argc, char **argv)
{
	char	**map;

	if (argc)
	{
		map = get_map(argv[1]);
		print_map(map);
	}
	return (0);
}
