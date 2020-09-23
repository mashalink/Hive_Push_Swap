/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:19:34 by mlink             #+#    #+#             */
/*   Updated: 2020/09/15 14:35:23 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_step_ra(t_all *all)
{
	int i;
	int j;
	int tmp;

	if (all->a_size < 2)
		return (1);
	i = 0;
	j = 0;
	tmp = all->a[0];
	while (i < all->a_size)
		all->a[i++] = all->a[++j];
	all->a[--i] = tmp;
	all->flag_print != 1 ? ft_steps(5) : 0;
	return (1);
}

int		ft_step_rb(t_all *all)
{
	int i;
	int j;
	int tmp;

	if (all->b_size < 2)
		return (1);
	i = 0;
	j = 0;
	tmp = all->b[0];
	while (i < all->b_size)
		all->b[i++] = all->b[++j];
	all->b[--i] = tmp;
	all->flag_print != 1 ? ft_steps(6) : 0;
	return (1);
}

int		ft_step_rr(t_all *all)
{
	all->flag_print = 1;
	ft_step_ra(all);
	ft_step_rb(all);
	ft_steps(7);
	all->flag_print = 0;
	return (1);
}
