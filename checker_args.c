/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:43:22 by tpicoule          #+#    #+#             */
/*   Updated: 2023/03/23 13:29:56 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_args(char **argv)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = ft_split(argv[i], ' ');
	while (tmp[i])
	{
		if (i > -2147483647 || i < 2147483647)
			i++;
		else
			return (1);
	}
	return (0);
}
