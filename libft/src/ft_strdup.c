/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:51:12 by mlink             #+#    #+#             */
/*   Updated: 2020/08/12 13:12:03 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *src)
{
	char	*cope;
	int		i;

	i = 0;
	if (!(cope = (char*)malloc(sizeof(*cope) * ft_strlen(src) + 1)))
		return (NULL);
	while (src[i])
	{
		cope[i] = src[i];
		i++;
	}
	cope[i] = '\0';
	return (cope);
}
