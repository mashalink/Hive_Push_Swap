/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 17:00:50 by mlink             #+#    #+#             */
/*   Updated: 2020/09/22 15:04:55 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		step_rra(t_all *all)
{
	int i;
	int tmp;

	if (all->a_size < 2)
		return (1);
	i = 0;
	tmp = all->a[all->a_size - 1];
	while (i < all->a_size)
	{
		all->a[all->a_size - i - 1] = all->a[all->a_size - i - 2];
		i++;
	}
	all->a[0] = tmp;
	return (1);
}

int		step_rrb(t_all *all)
{
	int i;
	int tmp;

	if (all->b_size < 2)
		return (1);
	i = 0;
	tmp = all->b[all->b_size - 1];
	while (i < all->b_size)
	{
		all->b[all->b_size - i - 1] = all->b[all->b_size - i - 2];
		i++;
	}
	all->b[0] = tmp;
	return (1);
}

int		step_rrr(t_all *all)
{
	step_rra(all);
	step_rrb(all);
	return (1);
}
