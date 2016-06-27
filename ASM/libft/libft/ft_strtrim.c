/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 19:31:46 by mcotfas           #+#    #+#             */
/*   Updated: 2015/12/16 13:49:05 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s)
{
	char		*ret;
	char		*tmp;
	int			startspace;
	char		*tmps;
	ssize_t		chars;

	if (!s)
		return (NULL);
	tmps = (char *)s;
	startspace = 0;
	while (ft_isspace(*tmps++))
		startspace++;
	chars = ft_strlen(s) - startspace;
	while (*tmps)
		tmps++;
	while (ft_isspace(*--tmps))
		chars--;
	ret = ft_strnew(chars);
	tmp = ret;
	while (ret && chars-- > 0)
		*tmp++ = s[startspace++];
	return (ret);
}
