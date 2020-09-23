/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 14:00:55 by mlink             #+#    #+#             */
/*   Updated: 2020/09/22 14:41:47 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_min_first(t_all *all)
{
	int i;

	i = 0;
	while (all->a[i] != all->min)
		i++;
	if (i < all->size / 2)
		while (all->a[0] != all->min)
			ft_step_ra(all);
	else
		while (all->a[0] != all->min)
			ft_step_rra(all);
}
