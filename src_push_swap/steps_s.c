/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:20:53 by mlink             #+#    #+#             */
/*   Updated: 2020/09/15 14:36:18 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_step_sa(t_all *all)
{
	int tmp;

	if (all->a_size < 2)
		return (1);
	tmp = all->a[0];
	all->a[0] = all->a[1];
	all->a[1] = tmp;
	all->flag_print != 1 ? ft_steps(0) : 0;
	return (1);
}

int		ft_step_sb(t_all *all)
{
	int tmp;

	if (all->b_size < 2)
		return (1);
	tmp = all->b[0];
	all->b[0] = all->b[1];
	all->b[1] = tmp;
	all->flag_print != 1 ? ft_steps(1) : 0;
	return (1);
}

int		ft_step_ss(t_all *all)
{
	all->flag_print = 1;
	ft_step_sa(all);
	ft_step_sb(all);
	ft_steps(2);
	all->flag_print = 0;
	return (1);
}
