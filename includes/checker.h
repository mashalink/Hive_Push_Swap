/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 12:53:22 by mlink             #+#    #+#             */
/*   Updated: 2020/09/22 15:27:55 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"

typedef struct	s_all
{
	int		*a;
	int		*b;
	int		size;
	int		a_size;
	int		b_size;
}				t_all;

int				main(int argc, char **argv);

void			ft_error(char *str);
void			ft_final_check(t_all *all);

t_all			*ft_memory_for_stack(t_all *all, int len);
int				ft_atoi_ps(const char *str);
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

#endif
