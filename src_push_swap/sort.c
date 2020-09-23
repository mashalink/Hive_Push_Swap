/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:13:21 by mlink             #+#    #+#             */
/*   Updated: 2020/09/22 14:39:45 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_min(t_all *all)
{
	int min;
	int i;

	i = 0;
	min = all->a[0];
	while (++i < all->size)
	{
		if (min > all->a[i])
			min = all->a[i];
	}
	all->min = min;
	return (min);
}

static int	ft_max(t_all *all)
{
	int max;
	int i;

	i = 0;
	max = all->a[0];
	while (++i < all->size)
	{
		if (max < all->a[i])
			max = all->a[i];
	}
	all->max = max;
	return (max);
}

void		ft_sort(t_all *all)
{
	int value_now;
	int i;
	int place;

	place = 0;
	all->checker[0] = ft_min(all);
	all->checker[all->size - 1] = ft_max(all);
	while (++place < all->size - 1)
	{
		i = -1;
		value_now = all->checker[all->size - 1];
		while (++i < all->size)
		{
			if (all->a[i] < value_now && all->a[i] > all->checker[place - 1])
				value_now = all->a[i];
		}
		all->checker[place] = value_now;
	}
}
