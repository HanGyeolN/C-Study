/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 18:09:19 by hna               #+#    #+#             */
/*   Updated: 2020/02/06 20:04:15 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <libgen.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

int		ft_is_dir(char *fpath);
int		ft_get_filesize(char *fpath);
void	ft_init_str(char *str, int size);

#endif
