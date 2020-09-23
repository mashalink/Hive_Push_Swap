/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 16:52:53 by mlink             #+#    #+#             */
/*   Updated: 2020/09/22 15:06:30 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		step_ra(t_all *all)
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
	return (1);
}

int		step_rb(t_all *all)
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
	return (1);
}

int		step_rr(t_all *all)
{
	step_ra(all);
	step_rb(all);
	return (1);
}
