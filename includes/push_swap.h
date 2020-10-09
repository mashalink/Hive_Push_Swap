/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 14:08:40 by mlink             #+#    #+#             */
/*   Updated: 2020/10/05 11:09:39 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"

# define ERR_MALLOC				"Malloc_Error\n"
# define ERR_DOUBLE				"Error: double numders\n"
# define ERR_NUMBER				"Error: need to be (-2147483649;2147483648)\n"
# define ERR_STRING				"Error: have not a number or empty value\n"
# define ERR_ARGV				"Error: doesn't contain a list of integers\n"

typedef struct	s_all
{
	int		*a;
	int		*b;
	int		*checker;
	int		size;
	int		a_size;
	int		b_size;
	int		flag_print;
	int		flag_step;
	int		min;
	int		max;
	int		count;
	int		min_i_a;
	int		min_j_b;
}				t_all;

int				main(int argc, char **argv);

void			ft_get_stack_str(t_all *all, char **str, int i);
void			ft_get_stack_argv(t_all *all, char **str, int i);
t_all			*ft_memory_for_stack(t_all *all, int len);

void			ft_error(char *str);
void			ft_steps(int step);
void			ft_final_check(t_all *all);

void			ft_sort(t_all *all);

int				ft_solve(t_all *all);

int				ft_check(t_all *all);
void			ft_check_three(t_all *all);

int				ft_put_smaller(t_all *all, int mean);
int				ft_put_smaller_large(t_all *all, int mean);
int				ft_put_bigger_large(t_all *all, int mean);

int				ft_find_next(t_all *all);

void			ft_get_next(t_all *all);

void			ft_min_first(t_all *all);

int				ft_step_sa(t_all *all);
int				ft_step_sb(t_all *all);
int				ft_step_ss(t_all *all);

int				ft_step_pa(t_all *all);
int				ft_step_pb(t_all *all);

int				ft_step_ra(t_all *all);
int				ft_step_rb(t_all *all);
int				ft_step_rr(t_all *all);

int				ft_step_rra(t_all *all);
int				ft_step_rrb(t_all *all);
int				ft_step_rrr(t_all *all);

#endif
