/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 10:48:01 by hna               #+#    #+#             */
/*   Updated: 2020/02/10 14:03:44 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <stdlib.h>
# include <unistd.h>

int				ft_strlen(char *str);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strcat(char *dest, char *src);
void			ft_putstr(char *str);
void			ft_putchar(char c);
void			ft_putnbr(int n);

#endif
