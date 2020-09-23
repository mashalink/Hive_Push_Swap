/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 14:18:34 by mlink             #+#    #+#             */
/*   Updated: 2020/09/22 14:58:52 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_get_1(t_all *all)
{
	while (all->min_i_a > 0 && all->min_j_b > 0)
	{
		ft_step_rr(all);
		all->min_j_b--;
		all->min_i_a--;
	}
	while (all->min_j_b-- > 0)
		ft_step_rb(all);
	while (all->min_i_a-- > 0)
		ft_step_ra(all);
}

static void	ft_get_2(t_all *all)
{
	while (all->min_i_a < all->a_size && \
	all->min_j_b < all->b_size && all->min_j_b != 0)
	{
		ft_step_rrr(all);
		all->min_j_b++;
		all->min_i_a++;
	}
	while (all->min_i_a++ < all->a_size)
		ft_step_rra(all);
	while (all->min_j_b++ < all->b_size)
		ft_step_rrb(all);
}

void		ft_get_next(t_all *all)
{
	if (all->flag_step == 1)
		ft_get_1(all);
	else if (all->flag_step == 2)
		ft_get_2(all);
	else if (all->flag_step == 3)
	{
		while (all->min_j_b-- > 0)
			ft_step_rb(all);
		while (all->min_i_a++ < all->a_size)
			ft_step_rra(all);
	}
	else if (all->flag_step == 4)
	{
		while (all->min_j_b++ < all->b_size)
			ft_step_rrb(all);
		while (all->min_i_a-- > 0)
			ft_step_ra(all);
	}
}
