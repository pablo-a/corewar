/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 19:36:21 by pabril            #+#    #+#             */
/*   Updated: 2016/06/10 14:23:09 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "corewar.h"

int		error(char *str)
{
	ft_putendl(str);
	ft_putendl(USAGE);
	exit(0);
}

int		perror_exit(char *error)
{
	perror(error);
	exit(0);
}
