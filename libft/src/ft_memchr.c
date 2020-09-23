/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 13:58:43 by mlink             #+#    #+#             */
/*   Updated: 2020/08/12 13:09:56 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char	*i;

	i = (unsigned char *)arr;
	while (n--)
	{
		if (*i == ((unsigned char)c))
			return (i);
		i++;
	}
	return (NULL);
}
