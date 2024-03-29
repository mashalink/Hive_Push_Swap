/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 18:19:44 by mlink             #+#    #+#             */
/*   Updated: 2020/08/12 13:08:52 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_isspace(int ch)
{
	return (ch == '\n' || ch == '\r' || ch == '\v' || ch == '\f'\
	|| ch == '\t' || ch == ' ');
}
