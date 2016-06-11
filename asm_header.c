/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 17:05:13 by hdebard           #+#    #+#             */
/*   Updated: 2016/06/11 17:29:20 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"


header_t		*asm_init_header(void)
{
	header_t		*new;

	if ((new = (t_header*)malloc(sizeof(header_t))) == NULL)
		return (NULL);
	bzero(new, sizeof(header_t));
	return (new);
}

header_t		*asm_create_header(void)
{
	header_t	*header;
	char		*prog_name;
	char		*comment;

	if ((header = asm_init_header()) == NULL)
		return (1);
	strcpy(header->prog_name, prog_name); // le nom qui doit fair PROG_NAME_LENGHT maximum
	strcpy(header->comment, comment); // le comment qui doit fair COMMENT_LENGHT maximum
	header->magic = COREWAR_EXEC_MAGIC; // magic == COREWAR-EXEC_MAGIC ?
	header->prog_size = 0; // size of program
	return (header);
}
