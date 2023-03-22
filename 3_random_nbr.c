/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_random_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:39:43 by tpicoule          #+#    #+#             */
/*   Updated: 2023/03/22 16:59:59 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dblist	*ft_two(t_dblist *pilea)
{
	if (pilea->top->value > pilea->bot->value)
	{
		ft_swap_a(pilea->top, pilea->top->next);
	}
	return (pilea);
}

t_dblist	*ft_tree(t_dblist *pilea)
{
	int	first;
	int	mid;
	int	last;

	first = pilea->top->value;
	mid = pilea->top->next->value;
	last = pilea->bot->value;
	if (first > mid && mid < last && last > first)
		ft_swap_a(pilea->top, pilea->top->next);
	else if (first > mid && mid > last && last < first)
	{
		ft_swap_a(pilea->top, pilea->top->next);
		ft_rra(pilea);
	}
	else if (first > mid && mid < last && last < first)
		ft_ra(pilea);
	else if (first < mid && mid > last && last > first)
	{
		ft_swap_a(pilea->top, pilea->top->next);
		ft_ra(pilea);
	}
	else if (first < mid && mid > last && last < first)
		ft_rra(pilea);
	return (pilea);
}

/* t_dblist	*ft_four(t_dblist *pilea, t_dblist *pileb)
{
	if (!pileb)
		return (pilea);
	if (pilea->length == 4)
	{
		ft_pa(pileb, pilea);
		ft_tree(pilea);
		if (pileb->top->value < pilea->top->value)
			ft_pa(pilea, pileb);
		else if (pileb->bot->value > pilea->bot->value)
		{
			ft_pa(pilea, pileb);
			ft_ra(pilea);
		}
		if (pileb->top->value > pilea->top->value
			&& pileb->top->value < pilea->top->prev->value)
		{
			ft_pa(pilea, pileb);
			ft_sa(pilea);
		}
		else
		{
			ft_pa();
		}
	}
	return (pilea);
}
 */

void	ft_check_five(t_dblist *pilea)
{
	if (!pilea)
		return ;
	ft_rra(pilea);
	ft_swap_a(pilea->top, pilea->top->next);
	ft_ra(pilea);
	ft_ra(pilea);
}

void	ft_check_five2(t_dblist *pilea)
{
	if (!pilea)
		return ;
	ft_swap_a(pilea->top, pilea->top->next);
	ft_ra(pilea);
	ft_swap_a(pilea->top, pilea->top->next);
	ft_rra(pilea);
}

t_dblist	*ft_five(t_dblist *pilea, t_dblist *pileb)
{
	if (!pileb)
		return (pilea);
	while (pilea->length != 3)
	{
		printf("longueur pileb === %d\n", pileb->length);
		if (ft_find_smallest(pilea) == 0)
			ft_pb(pilea, pileb);
		else if (ft_find_smallest(pilea) == 1)
		{
			ft_swap_a(pilea->top, pilea->top->next);
			ft_pb(pilea, pileb);
		}
		else if (ft_find_smallest(pilea) == 2)
		{
			ft_ra(pilea);
			ft_ra(pilea);
			ft_pb(pilea, pileb);
		}
		else if (ft_find_smallest(pilea) == 3 && pilea->length == 5)
		{
			ft_rra(pilea);
			ft_rra(pilea);
			ft_pb(pilea, pileb);
		}
		else if (ft_find_smallest(pilea) == 4 || ft_find_smallest(pilea) == 3)
		{
			ft_rra(pilea);
			ft_pb(pilea, pileb);
		}
	}
	ft_tree(pilea);
	ft_pa(pilea, pileb);
	ft_pa(pilea, pileb);
	return (pilea);
	}

/* 	while (pilea->length != 3)
		ft_pb(pilea, pileb); */
/* 	while (pileb->length > 0)
	{
		ft_pa(pilea, pileb);
		if (pilea->top->value > pilea->top->next->value
			&& pilea->top->value < pilea->top->next->next->value)
		{
			write (1, "caca1\n", 6);
			ft_swap_a(pilea->top, pilea->top->next);
		}
		if (pilea->top->value > pilea->bot->value)
		{
			write (1, "caca2\n", 6);
			ft_ra(pilea);
		}
		if (pilea->top->value < pilea->bot->value
			&& pilea->top->value > pilea->bot->prev->value)
		{
			write (1, "caca3\n", 6);
			ft_check_five(pilea);
		}
		if (pilea->top->value > pilea->top->next->value
			&& pilea->top->value > pilea->top->next->next->value
			&& pilea->top->value < pilea->bot->value
			&& pilea->top->value < pilea->bot->prev->value)
		{
			write (1, "caca4\n", 6);
			ft_check_five2(pilea);
		} */

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
