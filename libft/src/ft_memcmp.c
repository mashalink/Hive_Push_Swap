/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:15:09 by mlink             #+#    #+#             */
/*   Updated: 2020/08/12 13:10:02 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_memcmp(const void *arr1, const void *arr2, size_t len)
{
	size_t	i;
	char	*copy1;
	char	*copy2;

	copy1 = (char *)arr1;
	copy2 = (char *)arr2;
	i = 0;
	if (len == 0)
		return (0);
	while (i < len)
	{
		if (copy1[i] != copy2[i])
			return ((unsigned char)copy1[i] - (unsigned char)copy2[i]);
		i++;
	}
	return (0);
}
