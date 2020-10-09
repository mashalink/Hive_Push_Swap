/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 15:07:59 by mlink             #+#    #+#             */
/*   Updated: 2020/10/02 10:51:00 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

t_all		*ft_memory_for_stack(t_all *all, int len, int flag)
{
	if (len == 0)
		ft_error(ERR_ARGV);
	if (!(all = (t_all*)ft_memalloc(sizeof(t_all))))
		ft_error_vis(ERR_MALLOC	, all);
	all->flag = flag;
	if (!(all->a = (int*)ft_memalloc(sizeof(int) * len)))
		ft_error_vis(ERR_MALLOC	, all);
	if (!(all->b = (int*)ft_memalloc(sizeof(int) * len)))
		ft_error_vis(ERR_MALLOC	, all);
	all->size = len;
	all->a_size = len;
	all->b_size = 0;
	all->error_massage = NULL;
	return (all);
}

int			ft_atoi_ps(const char *str, t_all *all)
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
		ft_error_vis(ERR_STRING, all);
	if (x * negative > 2147483647 || x * negative < -2147483648)
		ft_error_vis(ERR_NUMBER, all);
	return ((int)x * negative);
}

static int	check_double(int n, t_all *all, int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		if (all->a[j] == n)
			return (0);
		j++;
	}
	return (1);
}

void		ft_get_stack_str(t_all *all, char **str, int i)
{
	int n;
	int j;

	j = 0;
	while (i < all->size)
	{
		n = ft_atoi_ps(str[i++], all);
		if (!check_double(n, all, j))
			ft_error_vis(ERR_DOUBLE, all);
		all->a[j++] = n;
	}
}

void		ft_get_stack_argv(t_all *all, char **str, int i)
{
	int n;
	int j;

	j = 0;
	while (i <= all->size + all->flag)
	{
		n = ft_atoi_ps(str[i++], all);
		if (!check_double(n, all, j))
			ft_error_vis(ERR_DOUBLE, all);
		all->a[j++] = n;
	}
}
