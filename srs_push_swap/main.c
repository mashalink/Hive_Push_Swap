/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 14:00:22 by mlink             #+#    #+#             */
/*   Updated: 2020/06/08 15:48:10 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void ft_error(char *str)
{
	write(1, str, ft_strlen(str));
	exit(1);
}

int		ft_atoi_(const char *str)
{
	long	negative;
	long	x;

	x = 0;
	negative = 1;
	while (*str == ' ' || *str == '\r' || *str == '\n' || *str == '\f' \
		|| *str == '\v' || *str == '\t')
		str++;
	if (*str == '-')
			negative = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		x = (x * 10) + (*str - '0');
		str++;
		if (x * negative > 2147483647 || x * negative < -2147483648)
			ft_error("Error\n");
	}
	if (str != '\0')
		ft_error("Error\n");
	return ((int)x * negative);
}

static int ft_len_array(char **str)
{
	int i;

	while (str[i])
		i++;
	return (i);
}

void ft_memory_for_stack(t_all *all, int len)
{
	if (!(all = (t_all*)ft_memalloc(sizeof(t_all))))
		ft_error("Malloc_Error\n");
	if (!(all->a = (int*)ft_memalloc(sizeof(int) * len)))
		ft_error("Malloc_Error\n");
	if (!(all->b = (int*)ft_memalloc(sizeof(int) * len)))
		ft_error("Malloc_Error\n");
	if (!(all->check = (int*)ft_memalloc(sizeof(int) * len)))
		ft_error("Malloc_Error\n");
	all->size = len;
}

void ckeck_double(int n, int *a, int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		if (a[j++] == n)
			return (0);
	}
	return (1);
}

void ft_get_stack(t_all *all, char **str, int i)
{
	long n;

	while(i < all->size)
	{
		n = ft_atoi(str[i]);
		if (!check_double((int)n, all->a, i))
			ft_error("Error\n");
		all->a[i] = n;
		i++;
	}
}

int main(int argc, char ** argv)
{
	char **str;
	int	len;
	t_all *all;

	if (argc > 1)
	{		
		if (argc == 2)
		{
			str = ft_strsplit(argv[1], ' ');
			len = ft_len_array(str);
		}
		else
			len = argc - 1;
		ft_memory_for_stack(&all, len);
		str ? ft_get_stack(all, str, 0) : ft_get_stack(all, argv, 1);
	}
	return (0);
}