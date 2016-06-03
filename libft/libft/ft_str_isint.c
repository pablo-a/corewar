//
// Created by mcotfas on 16/05/16.
//

#include "libft.h"

int ft_str_is_int(char *str)
{
	return (ft_strcmp(ft_itoa(ft_atoi(str)), str) == 0);
}
