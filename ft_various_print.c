/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_various_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakashi <rtakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 22:42:43 by rtakashi          #+#    #+#             */
/*   Updated: 2023/03/02 22:43:53 by rtakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *s)
{
	if (s == NULL)
		s = "(null)";
	ft_putstr_fd(s, 1);
	return ((int)ft_strlen(s));
}

int	print_ptr(unsigned long long p)
{
	char	*ptr;
	int		ret;

	ptr = change_ptr(p);
	if (ptr == NULL)
		return (0);
	ft_putstr_fd(ptr, 1);
	ret = ft_strlen(ptr);
	free(ptr);
	return (ret);
}

int	print_hex(unsigned int u_num, int case_n)
{
	char	*hex_arr;
	int		ret;

	hex_arr = change_base(u_num, 16);
	change_letter(hex_arr, case_n);
	ft_putstr_fd(hex_arr, 1);
	ret = ft_strlen(hex_arr);
	free(hex_arr);
	return (ret);
}

int	print_int(int n)
{
	char	*arr;
	int		ret;

	arr = ft_itoa(n);
	if (arr == NULL)
		return (0);
	ft_putstr_fd(arr, 1);
	ret = ft_strlen(arr);
	free(arr);
	return (ret);
}

int	print_un_int(unsigned int u_num)
{
	char			*arr;
	unsigned int	ret;
	int				digit;

	if (u_num == 0)
		arr = ft_strdup("0");
	else
	{
		digit = get_digit_u_num(u_num, 10);
		arr = (char *)ft_calloc(digit + 1, sizeof(char));
	}
	if (arr == NULL)
		return (0);
	while (u_num > 0)
	{
		arr[digit - 1] = u_num % 10 + '0';
		u_num /= 10;
		digit--;
	}
	ft_putstr_fd(arr, 1);
	ret = ft_strlen(arr);
	free(arr);
	return (ret);
}
