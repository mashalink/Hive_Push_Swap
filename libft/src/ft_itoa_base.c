/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 15:23:34 by mlink             #+#    #+#             */
/*   Updated: 2020/09/22 15:23:48 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_itoa_base(uintmax_t x, int base)
{
	char		*str;
	char		*base_s;
	uintmax_t	nbr;
	int			len;

	len = 0;
	nbr = x;
	base_s = "0123456789abcdef";
	while (nbr)
	{
		nbr /= base;
		len++;
	}
	str = ft_clean_str(len, x);
	while (x > 0)
	{
		str[--len] = base_s[x % base];
		x /= base;
	}
	return (str);
}
