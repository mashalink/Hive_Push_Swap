/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:09:03 by mlink             #+#    #+#             */
/*   Updated: 2020/08/14 13:51:43 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		step_pa(t_all *all)
{
	int count;

	if (all->b_stack_size < 1)
		return (1);
	count = 0;
	while (count <= all->a_stack_size)
	{
		all->a_stack[all->a_stack_size - count] = all->a_stack[all->a_stack_size - count - 1];
		count++;
	}
	all->a_stack[0] = all->b_stack[0];
	count = 0;
	while (count < all->b_stack_size)
	{
		all->b_stack[count] = all->b_stack[1 + count];
		count++;
	}
	all->a_stack_size += 1;
	all->b_stack_size -= 1;
	return(1);
}

int		step_pb(t_all *all)
{
	int count;

	if (all->a_stack_size < 1)
		return (1);
	count = 0;
	while (count <= all->b_stack_size)
	{
		all->b_stack[all->b_stack_size - count] = all->b_stack[all->a_stack_size - count - 1];
		count++;
	}
	all->b_stack[0] = all->a_stack[0];
	count = 0;
	while (count < all->a_stack_size)
	{
		all->a_stack[count] = all->a_stack[1 + count];
		count++;
	}
	all->a_stack_size -= 1;
	all->b_stack_size += 1;
	return(1);
}
