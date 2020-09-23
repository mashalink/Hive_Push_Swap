/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:38:59 by mlink             #+#    #+#             */
/*   Updated: 2020/08/12 13:09:48 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *dest, const void *src, int c,
size_t n)
{
	unsigned char	*dest2;
	unsigned char	*src2;

	dest2 = (unsigned char*)dest;
	src2 = (unsigned char*)src;
	while (n > 0)
	{
		*dest2 = *src2;
		dest2++;
		if (*src2 == (unsigned char)c)
			return (dest2);
		src2++;
		n--;
	}
	return (NULL);
}
