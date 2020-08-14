/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 16:52:53 by mlink             #+#    #+#             */
/*   Updated: 2020/08/14 13:51:52 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/checker.h"

int		step_ra(t_all *all)
{
	int i;
	int j;
	int tmp;

	if (all->a_stack_size < 2)
		return (1);
	i = 0;
	j = 0;
	tmp = all->a_stack[0];
	while (i < all->a_stack_size)
		all->a_stack[i++] = all->a_stack[++j];
	all->a_stack[--i] = tmp;
	return (1);
}

int		step_rb(t_all *all)
{
	int i;
	int j;
	int tmp;

	if (all->b_stack_size < 2)
		return (1);
	i = 0;
	j = 0;
	tmp = all->b_stack[0];
	while (i < all->b_stack_size)
		all->b_stack[i++] = all->b_stack[++j];
	all->b_stack[--i] = tmp;
	return (1);
}

int		step_rr(t_all *all)
{
	step_ra(all);
	step_rb(all);
	return (1);
}
