/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakashi <rtakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 22:17:02 by rtakashi          #+#    #+#             */
/*   Updated: 2023/03/07 23:07:56 by rtakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_digit_ptr(unsigned long long ptr)
{
	int	digit;

	digit = 0;
	while (ptr > 0)
	{
		ptr /= 16;
		digit++;
	}
	return (digit);
}

int	get_digit_u_num(unsigned int u_num, int base)
{
	int	digit;

	digit = 0;
	while (u_num > 0)
	{
		u_num /= base;
		digit++;
	}
	return (digit);
}

char	*change_ptr(unsigned long long ptr)
{
	int		digit;
	char	*hex;
	char	*ans;

	hex = "0123456789abcdef";
	if (ptr == 0)
		return (ft_strdup("0x0"));
	digit = get_digit_ptr(ptr);
	ans = (char *)ft_calloc(digit + 3, sizeof(char));
	if (ans == NULL)
		return (NULL);
	ans[0] = '0';
	ans[1] = 'x';
	while (ptr > 0)
	{
		// if (ptr % 16 < 10)
		// 	ans[digit + 1] = ptr % 16 + '0';
		// else
			ans[digit + 1] = hex[ptr % 16];
		ptr /= 16;
		digit--;
	}
	return (ans);
}

char	*change_base(unsigned int ux, int base)
{
	int		digit;
	char	*hex;
	char	*ans;

	hex = "0123456789abcdef";
	if (ux == 0)
		return (ft_strdup("0"));
	digit = get_digit_u_num(ux, 16);
	ans = (char *)ft_calloc(digit + 1, sizeof(char));
	if (ans == NULL)
		return (NULL);
	while (digit > 0)
	{
		// if (ux % base < 10)
		// 	ans[digit - 1] = ux % base + '0';
		// else
			ans[digit - 1] = hex[ux % base];
		ux /= base;
		digit--;
	}
	return (ans);
}

void	change_letter(char *hex_arr, int case_n)
{
	size_t	i;

	i = 0;
	if (case_n == 1)
	{
		while (hex_arr[i] != '\0')
		{
			hex_arr[i] = ft_tolower(hex_arr[i]);
			i++;
		}
	}
	else
	{
		while (hex_arr[i] != '\0')
		{
			hex_arr[i] = ft_toupper(hex_arr[i]);
			i++;
		}
	}
}
