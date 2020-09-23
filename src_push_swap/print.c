/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:07:46 by mlink             #+#    #+#             */
/*   Updated: 2020/09/15 14:31:51 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error(char *str)
{
	write(1, str, ft_strlen(str));
	exit(1);
}

void	ft_steps(int step)
{
	step == 0 ? ft_putstr("sa\n") : 0;
	step == 1 ? ft_putstr("sb\n") : 0;
	step == 2 ? ft_putstr("ss\n") : 0;
	step == 3 ? ft_putstr("pa\n") : 0;
	step == 4 ? ft_putstr("pb\n") : 0;
	step == 5 ? ft_putstr("ra\n") : 0;
	step == 6 ? ft_putstr("rb\n") : 0;
	step == 7 ? ft_putstr("rr\n") : 0;
	step == 8 ? ft_putstr("rra\n") : 0;
	step == 9 ? ft_putstr("rrb\n") : 0;
	step == 10 ? ft_putstr("rrr\n") : 0;
}

void	ft_final_check(t_all *all)
{
	if (ft_check(all))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}
