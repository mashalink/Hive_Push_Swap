/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:49:47 by mlink             #+#    #+#             */
/*   Updated: 2020/08/12 13:14:18 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include "../includes/libft.h"

static int	ft_line(char **s, char **line)
{
	int		len;
	char	*tmp;

	len = 0;
	while ((*s)[len] != '\n' && (*s)[len] != '\0')
		len++;
	if ((*s)[len] == '\n')
	{
		*line = ft_strsub(*s, 0, len);
		tmp = ft_strdup(&((*s)[len + 1]));
		if (*line == NULL || tmp == NULL)
			return (-1);
		free(*s);
		*s = tmp;
		if ((*s)[0] == '\0')
			ft_strdel(s);
	}
	else
	{
		*line = ft_strdup(*s);
		ft_strdel(s);
		if (*line == NULL)
			return (-1);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	int			ret;
	static char	*s[FD_SIZE];
	char		buff[BUFF_SIZE + 1];
	char		*tmp;

	if (fd < 0 || FD_SIZE < fd || line == NULL || BUFF_SIZE < 1)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strnew(0);
		if ((tmp = ft_strjoin(s[fd], buff)) == NULL)
			return (-1);
		free(s[fd]);
		s[fd] = tmp;
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
		return (0);
	else
		return (ft_line(&s[fd], line));
}
