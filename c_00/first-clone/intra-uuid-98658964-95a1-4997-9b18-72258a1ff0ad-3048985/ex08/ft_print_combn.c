/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:21:42 by hna               #+#    #+#             */
/*   Updated: 2020/01/23 21:53:42 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_n_to_n(int n, int m)
{
	n = '0' + n;
	m = '0' + m;
	while (n <= m)
	{
		write(1, &n, 1);
		n++;
	}
}

void	ft_print_combn(int n, int depth_now, int depth_end)
{
	write_n_to_n(1,9);
}

int main(){
	ft_print_combn(1, 0, 2);
}
