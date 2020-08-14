/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:03:01 by mlink             #+#    #+#             */
/*   Updated: 2020/08/14 13:52:08 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
int		step_sa(t_all *all)
{
	int tmp;

	if (all->a_stack_size < 2)
		return (1);
	tmp = all->a_stack[0];
	all->a_stack[0] = all->a_stack[1];
	all->a_stack[1] = tmp;
	return(1);
}

int		step_sb(t_all *all)
{
	int tmp;

	if (all->b_stack_size < 2)
		return (1);
	tmp = all->b_stack[0];
	all->b_stack[0] = all->b_stack[1];
	all->b_stack[1] = tmp;
	return(1);
}

int		step_ss(t_all *all)
{
	step_sa(all);
	step_sb(all);
	return(1);
}