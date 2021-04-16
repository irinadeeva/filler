/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 14:51:48 by bhugo             #+#    #+#             */
/*   Updated: 2021/04/16 14:59:02 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	drobilka2(char **mass_poiter, char **line, int i)
{
	char	*tail;

	*line = ft_strsub(*mass_poiter, 0, i);
	if (*line == NULL)
	{
		free(*mass_poiter);
		return (-1);
	}
	tail = ft_strdup(&((*mass_poiter)[i + 1]));
	if (tail == NULL)
	{
		free(*mass_poiter);
		return (-1);
	}
	free(*mass_poiter);
	*mass_poiter = tail;
	if ((*mass_poiter)[0] == '\0')
		ft_strdel(mass_poiter);
	return (1);
}

static int	drobilka(char **mass_pointer, char **line)
{
	int	i;

	i = 0;
	while ((*mass_pointer)[i] != '\n' && (*mass_pointer)[i] != '\0')
		i++;
	if ((*mass_pointer)[i] == '\n')
	{
		if (drobilka2(mass_pointer, line, i) == -1)
			return (-1);
	}
	else
	{
		*line = ft_strdup(*mass_pointer);
		if (*line == NULL)
		{
			free(*mass_pointer);
			return (-1);
		}
		ft_strdel(mass_pointer);
	}
	return (1);
}

static int	return_result(char **ms_ptr, char **line, int rd_res, int fd)
{
	if (rd_res < 0)
		return (-1);
	else if (rd_res == 0 && ms_ptr[fd] == NULL)
		return (0);
	else
		return (drobilka(ms_ptr + fd, line));
}

int	read_file(int fd, char *buff, char **mass_pointer)
{
	char	*tmp;

	if (mass_pointer[fd] == NULL)
	{
		mass_pointer[fd] = ft_strdup(buff);
		if (mass_pointer[fd] == NULL)
			return (-1);
	}
	else
	{
		tmp = ft_strjoin(mass_pointer[fd], buff);
		if (tmp == NULL)
		{
			free(mass_pointer[fd]);
			return (-1);
		}
		free(mass_pointer[fd]);
		mass_pointer[fd] = tmp;
	}
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	int			read_result;
	static char	*mass_pointer[10240];
	char		buff[BUFF_SIZE + 1];

	if (fd < 0 || fd > 10240 || line == NULL)
		return (-1);
	ft_bzero(buff, BUFF_SIZE + 1);
	read_result = read(fd, buff, BUFF_SIZE);
	while (read_result > 0)
	{
		buff[read_result] = '\0';
		if (read_file(fd, buff, mass_pointer) == -1)
			return (-1);
		if (ft_strchr(mass_pointer[fd], '\n'))
			break ;
		read_result = read(fd, buff, BUFF_SIZE);
	}
	return (return_result(mass_pointer, line, read_result, fd));
}
