/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 19:59:00 by hna               #+#    #+#             */
/*   Updated: 2020/01/23 20:03:32 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int quot;
	int rem;

	quot = 0;
	rem = 0;
	quot = *a / *b;
	rem = *a % *b;
	*a = quot;
	*b = rem;
}