/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_next.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 14:15:50 by mlink             #+#    #+#             */
/*   Updated: 2020/09/22 14:55:36 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_min_a(t_all *all)
{
	int i;
	int min;

	i = 1;
	min = all->a[0];
	while (i < all->a_size)
	{
		if (all->a[i] < min)
			min = all->a[i];
		i++;
	}
	return (min);
}

static int	ft_a_min_i(t_all *all, int j)
{
	int i;
	int min;

	i = 0;
	min = ft_min_a(all);
	if (all->b[j] < min && all->a[0] != min)
	{
		while (i < all->a_size)
		{
			if (min == all->a[i])
				return (i);
			i++;
		}
	}
	else
	{
		while (i < all->a_size)
		{
			if (all->a[i] < all->b[j] && all->b[j] < all->a[i + 1])
				return (i + 1);
			i++;
		}
	}
	return (i);
}

static void	ft_save(t_all *all, int a_min, int flag, int count)
{
	all->min_i_a = a_min;
	all->flag_step = flag;
	all->count = count;
}

static void	ft_min_steps(t_all *all, int j)
{
	int		a;
	int		b;
	int		c;
	int		d;
	int		i;

	i = ft_a_min_i(all, j);
	a = j > i ? j : i;
	a < all->count ? ft_save(all, i, 1, a) : 0;
	b = all->b_size - j > all->a_size - i ? all->b_size - j : all->a_size - i;
	b < all->count ? ft_save(all, i, 2, b) : 0;
	c = j + all->a_size - i;
	c < all->count ? ft_save(all, i, 3, c) : 0;
	d = all->b_size - j + i;
	d < all->count ? ft_save(all, i, 4, d) : 0;
}

int			ft_find_next(t_all *all)
{
	int j;
	int count;

	all->count = 100000;
	count = all->count;
	j = -1;
	while (++j < all->b_size)
	{
		ft_min_steps(all, j);
		if (count != all->count)
		{
			all->min_j_b = j;
			count = all->count;
		}
	}
	return (0);
}
