/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:38:15 by mlink             #+#    #+#             */
/*   Updated: 2020/08/12 13:12:27 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *destination, const char *append, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (destination[j] && len > j)
		j++;
	while (append[i] && len > (j + i + 1))
	{
		destination[j + i] = append[i];
		i++;
	}
	if (len > j)
		destination[j + i] = '\0';
	return (ft_strlen((char *)append) + j);
}
