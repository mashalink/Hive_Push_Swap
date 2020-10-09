/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:07:46 by mlink             #+#    #+#             */
/*   Updated: 2020/09/30 15:42:08 by mlink            ###   ########.fr       */
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
	step == 0 ? ft_putendl("sa") : 0;
	step == 1 ? ft_putendl("sb") : 0;
	step == 2 ? ft_putendl("ss") : 0;
	step == 3 ? ft_putendl("pa") : 0;
	step == 4 ? ft_putendl("pb") : 0;
	step == 5 ? ft_putendl("ra") : 0;
	step == 6 ? ft_putendl("rb") : 0;
	step == 7 ? ft_putendl("rr") : 0;
	step == 8 ? ft_putendl("rra") : 0;
	step == 9 ? ft_putendl("rrb") : 0;
	step == 10 ? ft_putendl("rrr") : 0;
}

void	ft_final_check(t_all *all)
{
	if (ft_check(all))
		ft_putendl("OK");
	else
		ft_putendl("KO");
}
