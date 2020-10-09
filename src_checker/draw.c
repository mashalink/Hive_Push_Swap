/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 11:42:25 by mlink             #+#    #+#             */
/*   Updated: 2020/09/30 11:53:44 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static int	ft_min(t_all *all)
{
	int min;
	int i;

	i = 0;
	min = all->a[0];
	while (++i < all->size)
	{
		if (min > all->a[i])
			min = all->a[i];
	}
	return (min);
}

static int	ft_max(t_all *all)
{
	int max;
	int i;

	i = 0;
	max = all->a[0];
	while (++i < all->size)
	{
		if (max < all->a[i])
			max = all->a[i];
	}
	return (max);
}

static int	ft_abc(int min, int max)
{
	if (min < 0)
		min = min * -1;
	if (max < 0)
		max = max * -1;
	return (max > min ? max : min);
}

static void	ft_first_info(t_draw *draw)
{
	int min;
	int max;

	min = ft_min(draw->all);
	max = ft_max(draw->all);
	draw->a_x = 50;
	draw->b_x = 650;
	draw->flag = 0;
	draw->x_step = 1;
	if (ft_abc(min, max) < 500)
		draw->x_step = 500 / ft_abc(min, max);
	else
	{
		while (ft_abc(min, max) / draw->x_step > 500)
			draw->x_step += 1;
		draw->flag = 1;
	}
	if (draw->all->size < 900)
		draw->y_step = 900 / draw->all->size;
	else
		draw->y_step = 1;
}

void		ft_visual_sort(t_all *all)
{
	t_draw	*draw;

	if (!(draw = (t_draw*)ft_memalloc(sizeof(t_draw))))
		exit(1);
	draw->mlx_ptr = mlx_init();
	draw->win_ptr = mlx_new_window(draw->mlx_ptr, WIN_W, WIN_H, "CHECKER");
	draw->all = all;
	if (draw->all->error_massage == NULL)
		ft_first_info(draw);
	ft_draw(draw);
	mlx_hook(draw->win_ptr, 2, 0, key_controls, draw);
	mlx_loop(draw->mlx_ptr);
	free(draw);
}
