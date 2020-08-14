/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 14:50:09 by mlink             #+#    #+#             */
/*   Updated: 2020/08/14 13:56:46 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

t_all		*ft_memory_for_stack(t_all *all, int len)
{
	if (!(all = (t_all*)ft_memalloc(sizeof(t_all))))
		ft_error("Malloc_Error\n");
	if (!(all->a_stack = (int*)ft_memalloc(sizeof(int) * len)))
		ft_error("Malloc_Error\n");
	if (!(all->b_stack = (int*)ft_memalloc(sizeof(int) * len)))
		ft_error("Malloc_Error\n");
	all->size = len;
	all->a_stack_size = len;
	all->b_stack_size = 0; 
	return (all);
}

int			ft_atoi_ps(const char *str)
{
	int		i;
	long	negative;
	long	x;

	x = 0;
	negative = 1;
	while ((*str > 8 && *str < 14) || *str == 32)
		str++;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		str++;
	i = 0;
	while (*str >= '0' && *str <= '9' && i++ < 11)
	{
		x = (x * 10) + (*str - '0');
		str++;
	}
	if (i == 0)
		ft_error("Error\n");
	if (x * negative > 2147483647 || x * negative < -2147483648)
		ft_error("Error\n");
	return ((int)x * negative);
}

void		ft_error(char *str)
{
	write(1, str, ft_strlen(str));
	exit(1);
}

int		check_double(int n, t_all *all, int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		if (all->a_stack[j] == n)
			return (0);
		j++;
	}
	return (1);
}

void	ft_get_stack_str(t_all *all, char **str, int i)
{
	int n; 
	int min;
	int max;
	int j;

	j = 0;
	while (i < all->size)
	{
		n = ft_atoi_ps(str[i++]);
		if (!check_double(n, all, j))
			ft_error("Error?\n");
		all->a_stack[j++] = n;
	}
	i = 0;
	min = all->a_stack[0];
	max = all->a_stack[0];
	while (++i < all->size)
	{
		if (min > all->a_stack[i])
			min = all->a_stack[i];
		if (max < all->a_stack[i])
			max = all->a_stack[i];
	}
	all->max = max;
	all->min = min;
}

void	ft_get_stack_argv(t_all *all, char **str, int i)
{
	int n; 
	int min;
	int max;
	int j;

	j = 0;
	while (i <= all->size)
	{
		n = ft_atoi_ps(str[i++]);
		if (!check_double(n, all, j))
			ft_error("Error?\n");
		all->a_stack[j++] = n;
	}
	i = 0;
	min = all->a_stack[0];
	max = all->a_stack[0];
	while (++i < all->size)
	{
		if (min > all->a_stack[i])
			min = all->a_stack[i];
		if (max < all->a_stack[i])
			max = all->a_stack[i];
	}
	all->max = max;
	all->min = min;
}

void	ft_final_check(t_all *all)
{
	if (ft_check(all))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

int		ft_check(t_all *all)
{
	int i;

	i = 1;
	if (all->a_stack_size == 1 && all->b_stack_size == 0)
		return (1);
	while (all->a_stack[i - 1] < all->a_stack[i] && all->b_stack_size == 0 && i <= all->a_stack_size)
		i++;
	if (!all->b_stack_size && i == all->a_stack_size)
		return (1);
	return (0);
}

int 	ft_steps(char *line, t_all *all)
{
		int i;

	i = 0;
	ft_strcmp(line, "sa") == 0 ? i = step_sa(all) : 0;
	ft_strcmp(line, "sb") == 0 ? i = step_sb(all) : 0;
	ft_strcmp(line, "ss") == 0 ? i = step_ss(all) : 0;
	ft_strcmp(line, "pa") == 0 ? i = step_pa(all) : 0;
	ft_strcmp(line, "pb") == 0 ? i = step_pb(all) : 0;
	ft_strcmp(line, "ra") == 0 ? i = step_ra(all) : 0;
	ft_strcmp(line, "rb") == 0 ? i = step_rb(all) : 0;
	ft_strcmp(line, "rr") == 0 ? i = step_rr(all) : 0;
	ft_strcmp(line, "rra") == 0 ? i = step_rra(all) : 0;
	ft_strcmp(line, "rrb") == 0 ? i = step_rrb(all) : 0;
	ft_strcmp(line, "rrr") == 0 ? i = step_rrr(all) : 0;
	return (0);
}

static int	ft_len_array(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		main(int argc, char **argv)
{
	char	**str;
	char	*line;
	t_all	*all;
	int		len;

	if (argc > 1)
	{
		str = NULL;
		all = NULL;
		if (argc == 2)
		{
			str = ft_strsplit(argv[1], ' ');
			len = ft_len_array(str);
		}
		else
			len = argc - 1;
		all = ft_memory_for_stack(all, len);
		str ? ft_get_stack_str(all, str, 0) : ft_get_stack_argv(all, argv, 1);
		while (get_next_line(0, &line) > 0)
		{
			ft_steps(line, all);
			free(line);
		}
		ft_final_check(all);
	}
	return (0);
}