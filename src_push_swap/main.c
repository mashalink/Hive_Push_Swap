/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 14:00:22 by mlink             #+#    #+#             */
/*   Updated: 2020/08/05 16:14:57 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_nword(char const *s, char c) //delete (only in lib)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != c)
		{
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (j);
}

char			**ft_strsplit(char const *s, char c) //delete (only in lib)
{
	char	**new;
	size_t	i;
	size_t	j;
	int		a;

	i = 0;
	a = 0;
	if (!s || !c)
		return (0);
	new = (char **)malloc(sizeof(*new) * (ft_nword(s, c) + 1));
	if (!new)
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
			new[a++] = ft_strsub(s, j, (i - j));
	}
	new[a] = 0;
	return (new);
}

void		ft_error(char *str)
{
	write(1, str, ft_strlen(str));
	exit(1);
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

static int	ft_len_array(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

t_all		*ft_memory_for_stack(t_all *all, int len)
{
	int	count;


	if (!(all = (t_all*)ft_memalloc(sizeof(t_all))))
		ft_error("Malloc_Error\n");
	if (!(all->a = (int*)ft_memalloc(sizeof(int) * len)))
		ft_error("Malloc_Error\n");
	if (!(all->b = (int*)ft_memalloc(sizeof(int) * len)))
		ft_error("Malloc_Error\n");
	if (!(all->checker = (int*)ft_memalloc(sizeof(int) * len)))
		ft_error("Malloc_Error\n");
	all->size = len;
	count = -1;
	while (++count < ac) //I'm not sure...
		all->a[count] = 0;
	count = -1;
	while (++count < ac) //I'm not sure...
		all->b[count] = 0;
	all->a_stack_size = len;
	all->b_stack_size = 0; 
	return (all);
}

int		ckeck_double(int n, int *a, int i)
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

void	ft_get_stack(t_all *all, char **str, int i)
{
	int n; 
	int min;
	int max;

	while (i < all->size)
	{
		n = ft_atoi_ps(str[i]);
		if (!check_double(n, all->a, i))
			ft_error("Error\n");
		all->a[i] = n;
		i++;
	}
	i = 0;
	min = all->a[0];
	max = all->a[0];
	while (++i < all->size)
	{
		if (min > all->a[i])
			min = all->a[i];
		if (max < all->a[i])
			max = all->a[i];
	}
	all->max = max;
	all->min = min;
}


void sort(t_all *all)
{
	int value_now;
	int i;
	int place;

	place = 0;
	all->cheker[0] = all->min;
	all->cheker[all->size] = all->max;
	while (++place < all->size)
	{
		i = -1;
		value_now = all->real[all->size];
		while (++i < all->size)
		{
			if (all->a[i] < value_now && all->a[i] > all->cheker[place - 1])
				value_now = all->a[i];
		}
		all->checker[place] = now;
	}
/*
	mem->mid_from = mem->real[0];
*/
}

// void		solve(t_all *all)
// {

// }

int		main(int argc, char **argv)
{
	char	**str;
	int		len;
	t_all	*all;

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
		all = ft_memory_for_stack(&all, len);
		str ? ft_get_stack(&all, str, 0) : ft_get_stack(&all, argv, 1);
		ft_sort(&all);
		//ft_solve(all);
	}
	return (0);
}


//Ucha
// int	ft_solve(t_mem *mem)
// {
// 	if (ft_order(mem))
// 		return (0);
// 	if (mem->size < 6)
// 		ft_small_solve(mem);
// 	else if (mem->size > 5 && mem->size < 251)
// 		ft_medium_solve(mem);
// 	else
// 		ft_large_solve(mem);
// 	if (!ft_order(mem))
// 		ft_solve(mem);
// 	return (0);
// }