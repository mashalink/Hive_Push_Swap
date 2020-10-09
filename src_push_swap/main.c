/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 14:00:22 by mlink             #+#    #+#             */
/*   Updated: 2020/09/29 13:09:01 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_len_array(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int			main(int argc, char **argv)
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
		all = ft_memory_for_stack(all, len);
		str ? ft_get_stack_str(all, str, 0) : ft_get_stack_argv(all, argv, 1);
		ft_sort(all);
		ft_solve(all);
	}
	return (0);
}
