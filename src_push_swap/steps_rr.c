/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:19:54 by mlink             #+#    #+#             */
/*   Updated: 2020/09/15 14:35:52 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_step_rra(t_all *all)
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
	all->flag_print != 1 ? ft_steps(8) : 0;
	return (1);
}

int		ft_step_rrb(t_all *all)
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
	all->flag_print != 1 ? ft_steps(9) : 0;
	return (1);
}

int		ft_step_rrr(t_all *all)
{
	all->flag_print = 1;
	ft_step_rra(all);
	ft_step_rrb(all);
	ft_steps(10);
	all->flag_print = 0;
	return (1);
}
