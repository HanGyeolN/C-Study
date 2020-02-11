/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 22:57:38 by hna               #+#    #+#             */
/*   Updated: 2020/02/10 21:54:41 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H

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
int				ft_error(int err_num);
void			ft_tail(t_fileinfo *fileinfo, int ntail);
void			ft_multi_tail(t_fileinfo *finfo, int ntail, int flag);
void			ft_tail_re(int ntail, char *pname);
char			*ft_strcat(char *dest, char *src);
void			ft_init_str(char *str, int size);
int				ft_atoi(char *str);

#endif
