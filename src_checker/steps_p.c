/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:09:03 by mlink             #+#    #+#             */
/*   Updated: 2020/09/22 15:15:59 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		step_pa(t_all *all)
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
	return (1);
}

int		step_pb(t_all *all)
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
	return (1);
}
