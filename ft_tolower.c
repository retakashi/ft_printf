/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakashi <rtakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:46:56 by rtakashi          #+#    #+#             */
/*   Updated: 2023/03/02 16:09:35 by rtakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		return (c + ('a' - 'A'));
	else
		return (c);
}

// #include <ctype.h>
// #include <stdio.h>

// int main(void)
// {
//     printf("%c",ft_tolower('A'));
//     return(0);
// }
