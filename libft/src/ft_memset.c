/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 10:13:10 by mlink             #+#    #+#             */
/*   Updated: 2020/08/12 13:10:40 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *destination, int c, size_t len)
{
	char	*ptr;

	ptr = (char *)destination;
	while (len > 0)
	{
		ptr[len - 1] = c;
		len--;
	}
	return (destination);
}
