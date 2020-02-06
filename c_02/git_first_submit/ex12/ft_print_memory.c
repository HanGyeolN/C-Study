/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 16:33:38 by hna               #+#    #+#             */
/*   Updated: 2020/01/26 20:51:25 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	hex_convert(unsigned long long int dec)
{
	char	base[16];
	char	ret;

	ft_strcpy(base, "0123456789abcdef");
	ret = base[dec];
	return (ret);
}

char	*ft_hex_convert(unsigned long long int div, char *dest)
{
	int						i;
	char					ret;
	unsigned long long int	mod;

	i = 15;
	ft_strcpy(dest, "0000000000000000");
	dest[16] = '\0';
	while (div > 15)
	{
		mod = div % 16;
		div = div / 16;
		dest[i] = hex_convert(mod);
		i--;
	}
	dest[i] = hex_convert(div);
	return (dest);
}

void	put_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, str + i, 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int			i;
	char					str[32];
	unsigned long long int	addr_int;

	i = 0;
	while (i < size)
	{
		if (i % 16 == 0)
		{
			addr_int = (unsigned long long int)addr + i;
			ft_hex_convert(addr_int, str);
			put_str(str);
			put_str(": ");
			put_str("\n");
		}
		i++;
	}
	return (addr);
}
