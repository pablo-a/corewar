/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_create_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 17:50:58 by hdebard           #+#    #+#             */
/*   Updated: 2016/06/19 22:22:17 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

int				asm_rev_int(int i)
{
	return ((int)(((i & 0xff) << 24) |
				((i & 0xff00) << 8) |
				((i & 0xff0000) >> 8) |
				((i & 0xff000000) >> 24)));
}

header_t		*asm_create_header(t_strct *strct)
{
	header_t		*header;
	t_byteline		*ptr;

	ptr = strct->bytelines;
	if ((header = (header_t*)malloc(sizeof(header_t))) == NULL)
		return (NULL);
	bzero(header, sizeof(header_t));
	strcpy(header->prog_name, strct->name);
	strcpy(header->comment, strct->comment);
	header->magic = asm_rev_int(COREWAR_EXEC_MAGIC);
	while (ptr)
	{
		if (ptr->label == 0)
			header->prog_size += ptr->len;
		ptr = ptr->next;
	}
	header->prog_size = asm_rev_int(header->prog_size);
	return (header);
}

char			*asm_find_file_name(char *file)
{
	char	*new;
	int		i;

	i = ft_strlen(file) - 1;
	while (file[i] && file[i] != '.')
		i--;
	if (file[i])
	{
		file[i] = 0;
		new = ft_strjoin(file, ".cor");
		file[i] = '.';
		return (new);
	}
	return (NULL);
}

int				asm_write_file(t_strct *strct, char *name)
{
	char		*cor_name;
	header_t	*new;
	t_byteline	*ptr;
	int			fd;

	ptr = strct->bytelines;
	new = asm_create_header(strct);
	if ((cor_name = asm_find_file_name(name)) == NULL)
		return (-1);
	if ((fd = open(cor_name, O_TRUNC | O_RDWR | O_CREAT, 0666)) == -1)
		return (-1);
	write(fd, new, sizeof(header_t));
//	int i;
	while (ptr)
	{
		if (ptr->label == 0)
		{
/*			ft_putstr("\33[34m");
			i = 0;
			while (i < ptr->len)
			{
				ft_putnbr(ptr->byte_line[i]);
				ft_putchar(' ');
				i++;
			}
			ft_putendl("\033[37m");*/
			write(fd, ptr->byte_line, ptr->len);
		}
		ptr = ptr->next;
	}
	if ((fd = close(fd)) == -1)
		return (-1);
	return (0);
}
