/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:05:37 by mlink             #+#    #+#             */
/*   Updated: 2020/09/30 16:08:53 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_sort_b(t_all *all)
{
	if (all->b[0] < all->a[0] && (all->a[all->a_size - 1] < all->b[0] || \
		all->a[all->a_size - 1] == all->max))
		ft_step_pa(all);
	else
	{
		ft_find_next(all);
		ft_get_next(all);
	}
}

static int	ft_small(t_all *all)
{
	int mean;

	if (all->size > 3)
	{
		mean = all->checker[all->size - 4];
		while (ft_put_smaller(all, mean))
		{
			if (ft_check(all))
				return (0);
			ft_step_pb(all);
		}
	}
	if (all->size == 2 && !ft_check(all))
		ft_step_sa(all);
	if (ft_check(all))
		return (0);
	ft_check_three(all);
	if (all->b_size == 2 && all->b[0] < all->b[1])
		ft_step_sb(all);
	while (all->b_size > 0)
		ft_step_pa(all);
	return (0);
}

static int	ft_medium(t_all *all)
{
	int mean;

	mean = all->checker[all->size - 4];
	while (ft_put_smaller(all, mean))
		ft_step_pb(all);
	ft_check_three(all);
	while (all->b_size > 0)
	{
		ft_sort_b(all);
	}
	ft_min_first(all);
	return (0);
}

static int	ft_large(t_all *all)
{
	int mean;

	mean = all->checker[all->size / 2];
	while (ft_put_smaller_large(all, mean))
		ft_step_pb(all);
	while (all->b_size > 0)
	{
		if (all->b[0] < all->a[0] && (all->a[all->a_size - 1] < all->b[0] || \
		all->a[all->a_size - 1] > mean))
			ft_step_pa(all);
		else
		{
			ft_find_next(all);
			ft_get_next(all);
		}
	}
	while (ft_put_bigger_large(all, mean))
		ft_step_pb(all);
	while (all->b_size > 0)
	{
		ft_sort_b(all);
	}
	ft_min_first(all);
	return (0);
}

int			ft_solve(t_all *all)
{
	if (ft_check(all))
		return (0);
	if (all->size < 6)
		ft_small(all);
	else if (all->size > 5 && all->size < 252)
		ft_medium(all);
	else
		ft_large(all);
	if (!ft_check(all))
		ft_solve(all);
	return (0);
}
