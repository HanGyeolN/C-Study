/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 22:16:18 by hna               #+#    #+#             */
/*   Updated: 2020/02/10 22:16:42 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CAT_H
# define FT_CAT_H

# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <libgen.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define MAX_BUF_SIZE 30000
# define FILEPATH_SIZE 500
# define ERR_MSG_SIZE 500

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
int				ft_is_dir(char *fpath);
int				ft_get_filesize(char *fpath);
void			ft_init_str(char *str, int size);

#endif
