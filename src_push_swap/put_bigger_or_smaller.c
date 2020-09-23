/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_bigger_or_smaller.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:49:05 by mlink             #+#    #+#             */
/*   Updated: 2020/09/22 14:38:45 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_put_smaller(t_all *all, int mean)
{
	int i;

	i = -1;
	while (++i < all->a_size)
	{
		if (all->a[i] <= mean)
		{
			while (i > 0)
			{
				ft_step_ra(all);
				i--;
			}
			return (1);
		}
	}
	return (0);
}

int		ft_put_bigger(t_all *all, int mean)
{
	int i;

	i = 0;
	while (i < all->a_size)
	{
		if (all->a[i] > mean && all->a[i] != all->max)
		{
			while (i > 0)
			{
				if (i-- > 0)
					ft_step_ra(all);
			}
			return (1);
		}
		i++;
	}
	return (0);
}
