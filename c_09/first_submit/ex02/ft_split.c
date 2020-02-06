/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:02:32 by hna               #+#    #+#             */
/*   Updated: 2020/02/04 17:02:40 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		is_sep(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		get_size(char *str, char *charset)
{
	int i;
	int set_size;
	int count;
	int flag;

	i = 0;
	count = 1;
	flag = 1;
	set_size = ft_strlen(charset);
	while (str[i])
	{
		if (is_sep(str[i], charset) == 1)
			flag = 1;
		else if (is_sep(str[i], charset) == 0 && flag == 1)
		{
			flag = 0;
			count++;
		}
		i++;
	}
	return (count);
}

char	*ft_strsep(char *str, char *charset)
{
	int		i;
	int		len;
	char	*sep_str;

	i = 0;
	len = 1;
	while (is_sep(str[len], charset) == 0 && str[len] != '\0')
		len++;
	sep_str = (char *)malloc(sizeof(char) * len);
	while (is_sep(str[i], charset) == 0 && str[i] != '\0')
	{
		sep_str[i] = str[i];
		i++;
	}
	sep_str[i] = '\0';
	return (sep_str);
}

char	**ft_split(char *str, char *charset)
{
	char	**ret;
	int		word_size;
	int		flag;
	int		word_idx;
	int		i;

	flag = 1;
	i = 0;
	word_idx = 0;
	word_size = get_size(str, charset);
	ret = (char **)malloc(sizeof(char *) * word_size);
	while (str[i])
	{
		if (is_sep(str[i], charset) == 1)
			flag = 1;
		else if (is_sep(str[i], charset) == 0 && flag == 1)
		{
			flag = 0;
			ret[word_idx] = ft_strsep(&str[i], charset);
			word_idx++;
		}
		i++;
	}
	ret[word_idx] = 0;
	return (ret);
}
