/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 22:30:13 by hna               #+#    #+#             */
/*   Updated: 2020/02/10 22:31:32 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <libgen.h>
# include <string.h>
# include <errno.h>

# define MAX_BUF_SIZE 30000
# define FILEPATH_SIZE 500
# define ERR_MSG_SIZE 500
# define STDERR 2
# define STDOUT 1
# define STDIN 0

typedef struct	s_fileinfo
{
	int		fd;
	int		size;
	int		errno_open;
	int		errno_read;
	char	type;
	char	filepath[FILEPATH_SIZE];
	char	pname[FILEPATH_SIZE];
}				t_fileinfo;

t_fileinfo		*get_fileinfo(char *fpath, char *pname);
void			set_fileinfo(t_fileinfo *fileinfo, char *fpath);
void			show_fileinfo(t_fileinfo *finfo);
void			init_fileinfo(t_fileinfo *fileinfo);

#endif
