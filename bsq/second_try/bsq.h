/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:57:09 by hna               #+#    #+#             */
/*   Updated: 2020/02/11 18:07:20 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>

# define BUF_SIZE 100

typedef struct	s_map_info
{
	char		empty_char;
	char		obstacle_char;
	char		full_char;
	int			nrow;
	int			ncol;
}				t_map_info;

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putstr_err(char *str);
void	ft_putnbr(int num);

#endif
