/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_check_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarrete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 11:37:21 by vbarrete          #+#    #+#             */
/*   Updated: 2016/06/14 12:26:15 by vbarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int asm_is_ind(char *str)
{
	if (!ft_atoi(str))
		return (0);
	return (1);
}

int asm_is_dir(char *str)
{
	if (str[0] != '%')
		return (0);
	if (str[1] != ':')
		if(!ft_atoi(++str[1]))
			return (0);
	return (1);
}

int asm_is_reg(char *str)
{
	int val;

	if (str[0] != 'r')
		return (0);
	if (ft_isdigit(str[1]))
		return (0);
	val = ft_atoi(++str)
	if (!val || val < 0 || val > REG_NUMBER)
		return (0);
	return (1);
}
