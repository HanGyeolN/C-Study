/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 10:02:45 by hna               #+#    #+#             */
/*   Updated: 2020/01/26 15:29:02 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_char(char c)
{
	if ('a' <= c && c <= 'z')
		return (1);
	else if ('A' <= c && c <= 'Z')
		return (2);
	else if ('0' <= c && c <= '9')
		return (3);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int i;
	int char_type;
	int flag;

	i = 0;
	flag = 1;
	while (str[i] != '\0')
	{
		char_type = check_char(str[i]);
		if (char_type == 0)
			flag = 1;
		else if (char_type == 3)
			flag = 0;
		else if (char_type == 1 && flag == 1)
		{
			flag = 0;
			str[i] -= 32;
		}
		else if (char_type == 2 && flag == 0)
			str[i] += 32;
		i++;
	}
	return (str);
}
