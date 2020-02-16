/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 10:35:35 by hna               #+#    #+#             */
/*   Updated: 2020/02/10 21:54:23 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_tail.h"

int		main(int argc, char **argv)
{
	t_fileinfo	*finfo;
	int			flag;
	int			ntail;
	int			i;

	flag = 0;
	ntail = ft_atoi(argv[2]);
	if (argc == 3)
		ft_tail_re(ntail, argv[0]);
	else if (argc >= 4)
	{
		i = 3;
		while (i < argc)
		{
			finfo = get_fileinfo(argv[i], argv[0]);
			if (argc == 4)
				ft_tail(finfo, ntail);
			else
				ft_multi_tail(finfo, ntail, flag);
			i++;
			free(finfo);
			flag = 1;
		}
	}
	return (0);
}
