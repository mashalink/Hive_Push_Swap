/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 11:09:04 by mlink             #+#    #+#             */
/*   Updated: 2020/08/12 13:09:28 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*copy;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new->next = NULL;
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		if (!(copy = malloc(content_size)))
		{
			free(new);
			return (NULL);
		}
		new->content = ft_memcpy(copy, content, content_size);
		new->content_size = content_size;
	}
	return (new);
}
