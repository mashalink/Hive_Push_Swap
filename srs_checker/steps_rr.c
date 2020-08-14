/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 17:00:50 by mlink             #+#    #+#             */
/*   Updated: 2020/08/14 13:52:01 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		step_rra(t_all *all)
{
	int i;
	int tmp;

	if (all->a_stack_size < 2)
		return (1);
	i = 0;
	tmp = all->a_stack[all->a_stack_size - 1];
	while (i < all->a_stack_size)
	{
		all->a_stack[all->a_stack_size - i - 1] = all->a_stack[all->a_stack_size - i - 2];
		i++;
	}
	all->a_stack[0] = tmp;
	return (1);
}

int		step_rrb(t_all *all)
{
	int i;
	int tmp;

	if (all->b_stack_size < 2)
		return (1);
	i = 0;
	tmp = all->b_stack[all->b_stack_size - 1];
	while (i < all->b_stack_size)
	{
		all->b_stack[all->b_stack_size - i - 1] = all->b_stack[all->b_stack_size - i - 2];
		i++;
	}
	all->b_stack[0] = tmp;
	return (1);
}

int		step_rrr(t_all *all)
{
	step_rra(all);
	step_rrb(all);
	return (1);
}