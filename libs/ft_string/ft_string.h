/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 10:48:01 by hna               #+#    #+#             */
/*   Updated: 2020/02/06 17:59:04 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <stdlib.h>
# include <unistd.h>

int				ft_atoi(char *str);
int				ft_atoi_base(char *str, char *base);
int				ft_strlen(char *str);
int				ft_str_is_alpha(char *str);
int				ft_str_is_uppercase(char *str);
int				ft_str_is_lowercase(char *str);
int				ft_str_is_numeric(char *str);
int				ft_str_is_printable(char *str);
int				ft_strcmp(char *s1, char *s2);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
char			*ft_strstr(char *str, char *to_find);

int				*ft_range(int min, int max);

char			*ft_strcpy(char *dest, char *src);
char			*ft_strncpy(char *dest, char *src, unsigned int n);
unsigned int	*ft_strlcpy(char *dest, char *src, unsigned int size);
char			*ft_strcat(char *dest, char *src);
char			*ft_strncat(char *dest, char *src, unsigned int nb);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
char			*ft_strdup(char *src);
char			*ft_strjoin(int size, char **strs, char *sep);
char			**ft_split(char *str, char *charset);
void			ft_putstr(char *str);
void			ft_putchar(char c);
void			ft_putnbr(int n);
void			ft_swap_int(int *a, int *b);
void			ft_init_str(char *str, int size);
void			ft_putstr_err(char *str);

#endif
