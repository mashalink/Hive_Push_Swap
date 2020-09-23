/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 15:48:27 by mlink             #+#    #+#             */
/*   Updated: 2020/08/12 13:13:30 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "stdio.h"

static size_t	ft_nword(char const *s, char c)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != c)
		{
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (j);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**new;
	size_t	i;
	size_t	j;
	int		a;

	i = 0;
	a = 0;
	if (!s || !c)
		return (0);
	new = (char **)malloc(sizeof(*new) * (ft_nword(s, c) + 1));
	if (!new)
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
			new[a++] = ft_strsub(s, j, (i - j));
	}
	new[a] = 0;
	return (new);
}
