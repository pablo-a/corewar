/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_cc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 16:16:20 by mcotfas           #+#    #+#             */
/*   Updated: 2016/04/25 16:18:40 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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

static void		print_wchar(wint_t nb, t_info *info)
{
	size_t	*oct;
	size_t	i;
	char	*bits;

	i = 1;
	bits = ft_itoa_base(nb, 2, "01");
	oct = (size_t *)malloc(sizeof(*oct) * 5);
	oct[0] = 0;
	define_oct(bits, oct);
	info->ret = info->ret + (int)oct[0];
	while (oct[0]-- != 0)
		write(1, &(oct[i++]), 1);
	free(oct);
	free(bits);
}

void			conv_cc(t_info *info, va_list ap)
{
	wint_t arg;

	print_buffer(info);
	arg = va_arg(ap, wint_t);
	print_wchar(arg, info);
}
