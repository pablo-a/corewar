/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 16:43:16 by mcotfas           #+#    #+#             */
/*   Updated: 2016/03/23 14:54:27 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_mem		get_line(t_mem mem)
{
	size_t			i;
	char			*tmp;

	i = 0;
	while (mem.buff[i] != '\n')
		i++;
	mem.line = ft_strsub(mem.buff, 0, i);
	tmp = ft_strsub(mem.buff, i + 1, ft_strlen(mem.buff) -
					ft_strlen(mem.line) - 1);
	ft_memdel((void**)(&mem.buff));
	mem.buff = tmp;
	if (!ft_strchr(mem.buff, '\n'))
		mem.has_line = FALSE;
	return (mem);
}

static t_mem		check_errors(char *ptr, t_mem mem)
{
	if (!ptr)
		mem.error = TRUE;
	return (mem);
}

static t_mem		read_file(ssize_t fd, t_mem mem)
{
	ssize_t		ret;
	char		*read_buff;
	char		*tmp;

	ret = -1;
	read_buff = ft_strnew(BUFF_SIZE);
	mem = check_errors(read_buff, mem);
	while (!mem.error && !mem.has_line &&
			(ret = read(fd, read_buff, BUFF_SIZE)) > 0)
	{
		mem.end = FALSE;
		tmp = ft_strjoin(mem.buff, read_buff);
		ft_memdel((void**)(&mem.buff));
		mem.buff = ft_strdup(tmp);
		ft_memdel((void**)(&tmp));
		if (ft_strchr(mem.buff, '\n'))
			mem.has_line = TRUE;
		read_buff = (char*)ft_memset(read_buff, '\0', BUFF_SIZE);
	}
	if (!mem.error && ret == -1)
		mem.error = TRUE;
	if (ret == 0)
		mem.end_read = TRUE;
	ft_memdel((void**)(&read_buff));
	return (mem);
}

static t_mem		update_mem(t_mem mem, ssize_t fd)
{
	if (mem.end_read && !mem.buff)
		mem.end = TRUE;
	if (!mem.error && !mem.has_line && !mem.end_read)
		mem = read_file(fd, mem);
	if (!mem.error && mem.buff && mem.has_line)
		mem = get_line(mem);
	if (!mem.error && mem.buff && mem.end_read)
	{
		if (*mem.buff == '\0')
			mem.end = TRUE;
		else
			mem.line = ft_strdup(mem.buff);
		ft_memdel((void**)(&mem.buff));
	}
	return (mem);
}

int					get_next_line(int fd, char **line)
{
	static t_mem mem[FD_MAX];

	if (fd < 0 || fd >= FD_MAX || !line)
		return (-1);
	mem[fd] = update_mem(mem[fd], fd);
	if (mem[fd].error == TRUE || mem[fd].end == TRUE)
	{
		mem[fd].end_read = FALSE;
		mem[fd].buff = NULL;
		mem[fd].has_line = FALSE;
		mem[fd].line = NULL;
		if (mem[fd].error == TRUE)
		{
			mem[fd].error = FALSE;
			return (-1);
		}
		else if (mem[fd].end == TRUE)
			return (0);
	}
	*line = mem[fd].line;
	return (1);
}
