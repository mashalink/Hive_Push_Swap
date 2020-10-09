/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 12:53:22 by mlink             #+#    #+#             */
/*   Updated: 2020/10/05 11:09:12 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include <mlx.h>

# define WIN_W 1250
# define WIN_H 1050

# define PINK		0xCC1A99
# define WHITE		0xDBE1E7
# define NEON_BLUE	0x00D4FF
# define NEON_GREEN	0x3FFF00

# define ERR_MALLOC			"Malloc_Error\n"
# define ERR_DOUBLE			"Error: double numders\n"
# define ERR_NUMBER			"Error: need to be (-2147483649;2147483648)\n"
# define ERR_STRING			"Error: have not a number or empty value\n"
# define ERR_COMMAND		"Error: wrong command\n"
# define ERR_ARGV			"Error: doesn't contain a list of integers\n"
# define ERR_HELP			"-v : for visualize the sorting\n"
# define ERR_VISUALISATION	"-v : for visualize the sorting\n-h : for help\n"

typedef struct	s_all
{
	int		*a;
	int		*b;
	int		size;
	int		a_size;
	int		b_size;
	int		flag;
	char	*error_massage;
	int		flag_error_malloc;
}				t_all;

typedef struct	s_draw
{
	int		a_x;
	int		b_x;
	int		color;
	int		y_step;
	int		x_step;
	int		flag;
	int		flag_a;
	int		flag_b;
	int		x_f;
	int		x_s;
	void	*mlx_ptr;
	void	*win_ptr;
	t_all	*all;
}				t_draw;

int				main(int argc, char **argv);
int				ft_steps(char *line, t_all *all);

void			ft_error(char *str);
void			ft_error_vis(char *str, t_all *all);
int				ft_check(t_all *all);
void			ft_final_check(t_all *all);

t_all			*ft_memory_for_stack(t_all *all, int len, int flag);
int				ft_atoi_ps(const char *str, t_all *all);
void			ft_get_stack_str(t_all *all, char **str, int i);
void			ft_get_stack_argv(t_all *all, char **str, int i);

int				step_pb(t_all *all);
int				step_pa(t_all *all);

int				step_ra(t_all *all);
int				step_rb(t_all *all);
int				step_rr(t_all *all);

int				step_rra(t_all *all);
int				step_rrb(t_all *all);
int				step_rrr(t_all *all);

int				step_sa(t_all *all);
int				step_sb(t_all *all);
int				step_ss(t_all *all);

void			ft_visual_sort(t_all *all);
int				ft_draw(t_draw *draw);
int				key_controls(int key, t_draw *draw);

#endif
