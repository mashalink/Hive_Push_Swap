/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:37:44 by mlink             #+#    #+#             */
/*   Updated: 2020/08/12 13:09:12 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *str;
	t_list *strsave;

	str = *alst;
	while (str)
	{
		strsave = str->next;
		del((str->content), (str->content_size));
		free(str);
		str = strsave;
	}
	*alst = NULL;
}
