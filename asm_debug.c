/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 04:39:58 by hdebard           #+#    #+#             */
/*   Updated: 2016/06/19 04:41:27 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void check_list(t_byteline *ptr, int i)
{
    if ( i == 1)
    {
        while (ptr)
        {
            printf("\033[34m[%s]\033[37m\n", ptr->name);
            ptr = ptr->next;
        }
    }
    else if ( i == 2)
    {
        while (ptr)
        {
            printf("\033[35m[%s]\033[37m\n", ptr->name);
            ptr = ptr->next;
        }
    }
    else if ( i == 3)
    {
        while (ptr)
        {
            printf("\033[36m[%s]\033[37m\n", ptr->name);
            ptr = ptr->next;
        }
    }
    else
    {
        while (ptr)
        {
            printf("\033[32m[%s]\033[37m\n", ptr->name);
            ptr = ptr->next;
        }
    }
}
