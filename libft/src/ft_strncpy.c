/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:57:28 by mlink             #+#    #+#             */
/*   Updated: 2020/08/12 13:12:51 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strncpy(char *destination, const char *source, size_t n)
{
	size_t i;

	i = 0;
	while (source[i] != '\0' && n > i)
	{
		destination[i] = source[i];
		i++;
	}
	while (n > i)
	{
		destination[i] = '\0';
		i++;
	}
	return (destination);
}
