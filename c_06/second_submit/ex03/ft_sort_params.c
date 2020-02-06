/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:08:37 by hna               #+#    #+#             */
/*   Updated: 2020/01/30 17:12:57 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_swap(char **s1, char **s2)
{
	char *temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

void	sort_words(char **words, int size)
{
	int ret;
	int min;
	int i;
	int j;

	i = 1;
	while (i < size - 1)
	{
		min = i;
		j = i + 1;
		while (j < size)
		{
			ret = ft_strcmp(words[min], words[j]);
			if (ret < 0)
			{
				ft_swap(&words[min], &words[j]);
				min = i;
			}
			j++;
		}
		i++;
	}
}

int		main(int argc, char *argv[])
{
	sort_words(argv, argc);
	argc -= 1;
	while (argc > 0)
	{
		ft_putstr(argv[argc]);
		ft_putstr("\n");
		argc--;
	}
	return (0);
}
