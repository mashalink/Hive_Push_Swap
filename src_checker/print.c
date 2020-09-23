/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 15:11:07 by mlink             #+#    #+#             */
/*   Updated: 2020/09/22 15:13:32 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void		ft_error(char *str)
{
	write(1, str, ft_strlen(str));
	exit(1);
}

static int	ft_check(t_all *all)
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
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}
