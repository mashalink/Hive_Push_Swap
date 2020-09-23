/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:19:18 by mlink             #+#    #+#             */
/*   Updated: 2020/09/15 14:35:01 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_step_pa(t_all *all)
{
	int count;

	if (all->b_size < 1)
		return (1);
	count = 0;
	while (count < all->a_size)
	{
		all->a[all->a_size - count] = all->a[all->a_size - count - 1];
		count++;
	}
	all->a[0] = all->b[0];
	all->a_size += 1;
	all->b_size -= 1;
	count = 0;
	while (count < all->b_size)
	{
		all->b[count] = all->b[1 + count];
		count++;
	}
	ft_steps(3);
	return (1);
}

int		ft_step_pb(t_all *all)
{
	int count;

	if (all->a_size < 1)
		return (1);
	count = 0;
	while (count < all->b_size)
	{
		all->b[all->b_size - count] = all->b[all->b_size - count - 1];
		count++;
	}
	all->b[0] = all->a[0];
	all->a_size -= 1;
	all->b_size += 1;
	count = 0;
	while (count < all->a_size)
	{
		all->a[count] = all->a[1 + count];
		count++;
	}
	ft_steps(4);
	return (1);
}
