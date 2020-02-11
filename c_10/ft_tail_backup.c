/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:50:27 by hna               #+#    #+#             */
/*   Updated: 2020/02/07 11:57:44 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft.h"
#define ERR_MSG_SIZE 500
#define STDIN 0
#define STDOUT 1
#define STDERR 2

#include <stdio.h>
#define FPATH_SIZE 500

void	ft_str_initcpy(char *dest, char *src, int dest_size)
{
	ft_init_str(dest, dest_size);
	ft_strcpy(dest, src);
}

void	ft_display_file(fd)
{
	char	buf;

	while (read(fd, &buf, 1))
		write(1, &buf, 1);
}

void	ft_tail(fpath, tailno)
{
	int		file_idx;
	int		fd;
	int		size;
	int		readn;
	char	buf;

	file_idx = 0;
	fd = open(fpath, O_RDONLY);
	size = ft_get_filesize(fpath);
	readn = read(fd, &buf, 1);
	while (readn && file_idx < size - tailno)
		readn = read(fd, &buf, 1);
	ft_display_file(fd);

	close(fd);



void	ft_tail_re()
{
	read(0, 

int		main(int argc, char **argv)
{
	int		fd;
	char	fpath[FPATH_SIZE];

	fd = 0;
	ft_str_initcpy(fpath, argv[3], FPATH_SIZE);
	while (

		
