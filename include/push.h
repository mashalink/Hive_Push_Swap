/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 14:08:40 by mlink             #+#    #+#             */
/*   Updated: 2020/06/08 15:11:02 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

typedef struct	s_all
{
	int		*a;
	int		*b;
	int		*check;
	int		size;
}				t_all;


int main(int args, char ** argv);

#endif