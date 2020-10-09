/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 14:50:09 by mlink             #+#    #+#             */
/*   Updated: 2020/10/02 10:46:45 by mlink            ###   ########.fr       */
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

int			ft_steps(char *line, t_all *all)
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
		ft_error_vis(ERR_COMMAND, all);
	return (0);
}

static void	ft_take_and_check(t_all *all)
{
	char	*line;

	if (all->flag)
		ft_visual_sort(all);
	else
	{
		while (get_next_line(0, &line) > 0)
		{
			ft_steps(line, all);
			free(line);
		}
		ft_final_check(all);
	}
}

static int	ft_chech_flag(char **argv)
{
	if (!ft_strcmp(argv[1], "-v"))
		return (1);
	else if (!ft_strcmp(argv[1], "-c"))
		return (1);
	else if (!ft_strcmp(argv[1], "-h"))
		ft_error(ERR_HELP);
	else if (argv[1][0] == '-')
		ft_error(ERR_VISUALISATION);
	return (0);
}

int			main(int argc, char **argv)
{
	char	**str;
	t_all	*all;
	int		len;
	int		flag;

	if (argc > 1)
	{
		str = NULL;
		all = NULL;
		flag = ft_chech_flag(argv);
		if (argc == 2 || (argc == 3 && flag))
		{
			str = ft_strsplit((flag ? argv[2] : argv[1]), ' ');
			len = ft_len_array(str);
		}
		else
			len = argc - (flag ? 2 : 1);
		all = ft_memory_for_stack(all, len, flag);
		if (str)
			ft_get_stack_str(all, str, 0);
		else
			ft_get_stack_argv(all, argv, (flag ? 2 : 1));
		ft_take_and_check(all);
	}
	return (0);
}
