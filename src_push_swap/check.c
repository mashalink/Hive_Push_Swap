/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:16:54 by mlink             #+#    #+#             */
/*   Updated: 2020/09/30 15:40:10 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_check(t_all *all)
{
	int i;

	i = 1;
	if (all->a_size == 1 && all->b_size == 0)
		return (1);
	while (all->a[i - 1] < all->a[i] && all->b_size == 0 && i < all->a_size)
		i++;
	if (!all->b_size && i == all->a_size)
		return (1);
	return (0);
}

void	ft_check_three(t_all *all)
{
	if ((all->a[0] > all->a[1] && all->a[1] > all->a[2]) || \
	(all->a[0] > all->a[1] && all->a[2] > all->a[0]))
	{
		if (all->b[0] < all->b[1])
			ft_step_ss(all);
		else
			ft_step_sa(all);
		ft_check_three(all);
	}
	else if (all->a[0] > all->a[2] && all->a[2] > all->a[1])
	{
		if (all->b[0] < all->b[all->b_size - 1])
			ft_step_rr(all);
		else
			ft_step_ra(all);
	}
	else if ((all->a[0] < all->a[2] && all->a[1] > all->a[2]) || \
	(all->a[0] < all->a[1] && all->a[0] > all->a[2]))
	{
		if (all->b[0] < all->b[all->b_size - 1])
			ft_step_rrr(all);
		else
			ft_step_rra(all);
		ft_check_three(all);
	}
}
