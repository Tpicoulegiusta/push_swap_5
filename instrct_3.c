/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instrct_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:14:51 by tpicoule          #+#    #+#             */
/*   Updated: 2023/03/22 17:15:49 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_smallest(t_dblist *pilea)
{
	t_node	*node;
	int		tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	node = pilea->top;
	tmp = pilea->top->value;
	while (i < pilea->length)
	{
		if (tmp > node->value)
		{
			tmp = node->value;
			j = i;
		}
		node = node->next;
		i++;
	}
	free(node);
	return (j);
}

void	ft_smallest_at_2(t_dblist *pilea, t_dblist *pileb)
{
	ft_ra(pilea);
	ft_ra(pilea);
	ft_pb(pilea, pileb);
}

void	ft_smallest_at_3(t_dblist *pilea, t_dblist *pileb)
{
	ft_rra(pilea);
	ft_rra(pilea);
	ft_pb(pilea, pileb);
}
