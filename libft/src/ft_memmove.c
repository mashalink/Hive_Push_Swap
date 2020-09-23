/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 10:55:59 by mlink             #+#    #+#             */
/*   Updated: 2020/08/12 13:10:28 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *destination, const void *source, size_t len)
{
	if (destination > source)
	{
		while (len-- > 0)
			((unsigned char *)destination)[len] = \
			((unsigned char *)source)[len];
	}
	else if (destination < source)
		ft_memcpy(destination, source, len);
	return (destination);
}
