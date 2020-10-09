/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 14:08:04 by mlink             #+#    #+#             */
/*   Updated: 2020/09/30 10:53:44 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static int	ft_last_step(char *line, t_draw *draw)
{
	draw->flag_a = 0;
	draw->flag_b = 0;
	ft_strcmp(line, "sa") == 0 ? draw->flag_a = 1 : 0;
	ft_strcmp(line, "sb") == 0 ? draw->flag_b = 1 : 0;
	ft_strcmp(line, "ss") == 0 ? draw->flag_a = 1 : 0;
	ft_strcmp(line, "ss") == 0 ? draw->flag_b = 1 : 0;
	ft_strcmp(line, "pa") == 0 ? draw->flag_a = 2 : 0;
	ft_strcmp(line, "pb") == 0 ? draw->flag_b = 2 : 0;
	ft_strcmp(line, "ra") == 0 ? draw->flag_a = 3 : 0;
	ft_strcmp(line, "rb") == 0 ? draw->flag_b = 3 : 0;
	ft_strcmp(line, "rr") == 0 ? draw->flag_a = 3 : 0;
	ft_strcmp(line, "rr") == 0 ? draw->flag_b = 3 : 0;
	ft_strcmp(line, "rra") == 0 ? draw->flag_a = 4 : 0;
	ft_strcmp(line, "rrb") == 0 ? draw->flag_b = 4 : 0;
	ft_strcmp(line, "rrr") == 0 ? draw->flag_a = 4 : 0;
	ft_strcmp(line, "rrr") == 0 ? draw->flag_b = 4 : 0;
	return (0);
}

static void	ft_draw_next(t_draw *draw)
{
	char	*line;

	if ((get_next_line(0, &line)) > 0)
	{
		ft_steps(line, draw->all);
		ft_last_step(line, draw);
		ft_draw(draw);
		if (draw->all->error_massage == NULL)
			mlx_string_put(draw->mlx_ptr, draw->win_ptr, 590, 520, WHITE, line);
		free(line);
	}
	else
	{
		draw->flag_a = 0;
		draw->flag_b = 0;
		ft_draw(draw);
		if (ft_check(draw->all) && draw->all->error_massage == NULL)
			mlx_string_put(draw->mlx_ptr, draw->win_ptr,\
			50, 50, WHITE, "OK");
		else if (draw->all->error_massage == NULL)
			mlx_string_put(draw->mlx_ptr, draw->win_ptr,\
			50, 50, WHITE, "KO");
	}
}

int			key_controls(int key, t_draw *draw)
{
	if (key == 53)
		exit(0);
	if (key == 124 || key == 24 || key == 126)
		ft_draw_next(draw);
	return (1);
}
