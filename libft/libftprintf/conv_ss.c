/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_ss.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 15:52:41 by mcotfas           #+#    #+#             */
/*   Updated: 2016/04/25 15:57:01 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static size_t	count_oct(t_info *info, size_t nb)
{
	size_t	i;
	char	*bits;
	size_t	ret;

	bits = ft_itoa_base(nb, 2, "01");
	i = ft_strlen(bits);
	if (i <= 7)
		ret = 1;
	else if (i <= 11)
		ret = 2;
	else if (i <= 16)
		ret = 3;
	else
		ret = 4;
	free(bits);
	if (info->isprec && info->prec < (info->oct + ret))
		ret = 0;
	return (ret);
}

static size_t	extract_oct(char *bits, size_t start, size_t end, size_t val)
{
	char	ret[6];
	size_t	i;

	i = 0;
	while (i < end - start)
	{
		ret[i] = bits[i + start];
		i++;
	}
	return (ft_bin_to_dec(ret) | val);
}

static void		define_oct(char *bits, size_t *oct)
{
	size_t	i;

	i = ft_strlen(bits);
	if (i <= 7 && (oct[0] = 1))
		oct[1] = ft_bin_to_dec(bits);
	else if (i <= 11 && (oct[0] = 2))
	{
		oct[1] = extract_oct(bits, 0, i - 6, 192);
		oct[2] = extract_oct(bits, i - 6, i, 128);
	}
	else if (i <= 16 && (oct[0] = 3))
	{
		oct[1] = extract_oct(bits, 0, i - 12, 224);
		oct[2] = extract_oct(bits, i - 12, i - 6, 128);
		oct[3] = extract_oct(bits, i - 6, i, 128);
	}
	else if ((oct[0] = 4))
	{
		oct[1] = extract_oct(bits, 0, i - 18, 240);
		oct[2] = extract_oct(bits, i - 18, i - 12, 128);
		oct[3] = extract_oct(bits, i - 12, i - 6, 128);
		oct[4] = extract_oct(bits, i - 6, i, 128);
	}
}

static void		print_wchar(size_t nb, t_info *info)
{
	size_t	*oct;
	size_t	i;
	char	*bits;

	i = 1;
	bits = ft_itoa_base(nb, 2, "01");
	oct = (size_t *)malloc(sizeof(*oct) * 5);
	oct[0] = 0;
	define_oct(bits, oct);
	if (info->isprec && info->prec < (info->oct2 + oct[0]))
	{
		ft_memdel((void**)&oct);
		ft_strdel(&bits);
		return ;
	}
	info->oct2 = info->oct2 + oct[0];
	info->ret = info->ret + (int)oct[0];
	while (oct[0]-- != 0)
		write(1, &(oct[i++]), 1);
	ft_memdel((void**)&oct);
	ft_strdel(&bits);
}

void			conv_ss(t_info *info, va_list ap)
{
	wchar_t		*wstr;
	wchar_t		*wstr2;

	print_buffer(info);
	wstr = va_arg(ap, wchar_t *);
	wstr2 = wstr;
	if (!wstr && (info->ret = info->ret + 6))
		ft_putstr(NULL);
	else
	{
		while (*wstr != '\0')
			info->oct = info->oct + count_oct(info, (size_t)*wstr++);
		if (!info->flag->minus)
			transform_char(info, info->oct);
		if (info->str)
			print_buffer(info);
		while (*wstr2 != '\0')
			print_wchar((size_t)*wstr2++, info);
		if (info->flag->minus)
			transform_char(info, info->oct);
	}
}
