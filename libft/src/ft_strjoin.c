/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:27:56 by mlink             #+#    #+#             */
/*   Updated: 2020/08/12 13:12:21 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;

	if (!s1 || !s2)
		return (0);
	new = ft_strnew(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (!new)
		return (0);
	ft_strcpy(new, s1);
	ft_strcat(new, s2);
	return (new);
}
