/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 13:48:55 by mlink             #+#    #+#             */
/*   Updated: 2020/08/12 13:13:42 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*new;
	unsigned int	i;

	if (!s)
		return (NULL);
	new = ft_strnew(len);
	if (!new)
		return (NULL);
	i = 0;
	while (len-- > 0)
	{
		new[i] = s[start + i];
		i++;
	}
	return (new);
}
