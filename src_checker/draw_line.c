/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 14:03:58 by mlink             #+#    #+#             */
/*   Updated: 2020/09/30 10:39:56 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static void	ft_color(char stack, int *x, int i, t_draw *draw)
{
	if ((draw->flag_a == 1 && stack == 'a' && (i == 0 || i == 1))\
	|| (draw->flag_b == 1 && stack == 'b' && (i == 0 || i == 1)))
		draw->color = WHITE;
	else if ((draw->flag_a == 2 && stack == 'a' && i == 0)\
	|| (draw->flag_b == 2 && stack == 'b' && i == 0))
		draw->color = WHITE;
	else if ((draw->flag_a == 3 && stack == 'a' && i == draw->all->a_size - 1)\
	|| (draw->flag_b == 3 && stack == 'b' && i == draw->all->b_size - 1))
		draw->color = WHITE;
	else if ((draw->flag_a == 4 && stack == 'a' && i == 0)\
	|| (draw->flag_b == 4 && stack == 'b' && i == 0))
		draw->color = WHITE;
	else if (x[i] > 0)
		draw->color = PINK;
	else if (x[i] < 0)
		draw->color = NEON_BLUE;
	else
		draw->color = NEON_GREEN;
}

static void	ft_draw_line(t_draw *draw, int y)
{
	int i;
	int j;

	j = y;
	y += draw->y_step;
	while (j <= y)
	{
		i = draw->x_s;
		while (i <= draw->x_f)
		{
			mlx_pixel_put(draw->mlx_ptr, draw->win_ptr, i, j, draw->color);
			i++;
		}
		j++;
	}
}

static void	ft_draw_a(t_draw *draw)
{
	int i;

	i = -1;
	draw->x_s = draw->a_x;
	while (++i < draw->all->a_size && (75 + draw->y_step * i) < 951)
	{
		ft_color('a', draw->all->a, i, draw);
		if (draw->flag)
		{
			if (draw->all->a[i] > 0)
				draw->x_f = draw->all->a[i] / draw->x_step + draw->a_x;
			else
				draw->x_f = draw->all->a[i] * -1 / draw->x_step + draw->a_x;
		}
		else
		{
			if (draw->all->a[i] > 0)
				draw->x_f = draw->all->a[i] * draw->x_step + draw->a_x;
			else
				draw->x_f = draw->all->a[i] * -1 * draw->x_step + draw->a_x;
		}
		if (draw->all->a[i] == 0)
			draw->x_f = draw->a_x;
		ft_draw_line(draw, 75 + draw->y_step * i);
	}
}

static void	ft_draw_b(t_draw *draw)
{
	int i;

	i = -1;
	draw->x_s = draw->b_x;
	while (++i < draw->all->b_size && (75 + draw->y_step * i) < 951)
	{
		ft_color('b', draw->all->b, i, draw);
		if (draw->flag)
		{
			if (draw->all->b[i] > 0)
				draw->x_f = draw->all->b[i] / draw->x_step + draw->b_x;
			else
				draw->x_f = draw->all->b[i] * -1 / draw->x_step + draw->b_x;
		}
		else
		{
			if (draw->all->b[i] > 0)
				draw->x_f = draw->all->b[i] * draw->x_step + draw->b_x;
			else
				draw->x_f = draw->all->b[i] * -1 * draw->x_step + draw->b_x;
		}
		if (draw->all->b[i] == 0)
			draw->x_f = draw->b_x;
		ft_draw_line(draw, 75 + draw->y_step * i);
	}
}

int			ft_draw(t_draw *draw)
{
	mlx_clear_window(draw->mlx_ptr, draw->win_ptr);
	if (draw->all->error_massage)
		mlx_string_put(draw->mlx_ptr, draw->win_ptr, 50,\
		30, WHITE, draw->all->error_massage);
	else
	{
		ft_draw_a(draw);
		ft_draw_b(draw);
	}
	return (0);
}
