/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 14:08:40 by mlink             #+#    #+#             */
/*   Updated: 2020/08/05 13:53:55 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct	s_all
{
	int		*a;
	int		*b;
	int		*checker;
	int		size;
	int		a_stack_size;
	int		b_stack_size:
	int		max;
	int		min;
}				t_all;


int main(int argc, char ** argv);

#endif