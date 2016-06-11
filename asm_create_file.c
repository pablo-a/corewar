/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_create_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 17:50:58 by hdebard           #+#    #+#             */
/*   Updated: 2016/06/11 17:51:37 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*asm_find_file_name(char *file)
{
	char	**split;
	char	*new;

	split = ft_strsplit(file, '.');
	new = split[0];
	new = ft_strjoin(new, ".cor");
	return (new);
}
