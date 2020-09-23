/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 14:50:09 by mlink             #+#    #+#             */
/*   Updated: 2020/09/23 09:32:53 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static int	ft_len_array(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	ft_steps(char *line, t_all *all)
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
	if (i != 1)
		ft_error("Error\n");
	return (0);
}

int			main(int argc, char **argv)
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
		argc != 2 ? len = argc - 1 : 0;
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
