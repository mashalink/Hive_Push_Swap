/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 15:11:07 by mlink             #+#    #+#             */
/*   Updated: 2020/09/30 15:43:08 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void		ft_error(char *str)
{
	ft_putendl(str);
	exit(1);
}

void		ft_error_vis(char *str, t_all *all)
{
	if (all->flag)
		all->error_massage = str;
	else
	{
		ft_putendl(str);
		exit(1);
	}
}

int			ft_check(t_all *all)
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

void		ft_final_check(t_all *all)
{
	if (ft_check(all))
		ft_putendl("OK");
	else
		ft_putendl("KO");
}
