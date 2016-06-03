/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 16:12:23 by mcotfas           #+#    #+#             */
/*   Updated: 2016/04/25 15:11:40 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin_free(char *s1, char *s2)
{
	char	*ret;
	char	*tret;
	char	*ts1;
	char	*ts2;

	ts1 = s1;
	ts2 = s2;
	if (!s1 && !s2)
		return (ft_strnew(0));
	else if (!s1)
		return (s2);
	else if (!s2)
		return (s1);
	ret = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	tret = ret;
	while (*ts1 && tret)
		*tret++ = *ts1++;
	while (*ts2 && tret)
		*tret++ = *ts2++;
	if (tret)
		*tret = '\0';
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (ret);
}
