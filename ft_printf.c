/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reira <reira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:47:00 by rtakashi          #+#    #+#             */
/*   Updated: 2024/10/01 18:23:43 by reira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
static int	print_char(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	find_type(char *fmt, size_t i, va_list *ap)
{
	int	ans;

	ans = 0;
	if (fmt[i] == 'c')
		ans += print_char((int)va_arg(*ap, int));
	else if (fmt[i] == 's')
		ans += print_str((char *)va_arg(*ap, char *));
	else if (fmt[i] == 'p')
		ans += print_ptr((unsigned long long)va_arg(*ap, void *));
	else if (fmt[i] == 'd' || fmt[i] == 'i')
		ans += print_int((int)va_arg(*ap, int));
	else if (fmt[i] == 'u')
		ans += print_un_int((unsigned int)va_arg(*ap, unsigned int));
	else if (fmt[i] == 'x')
		ans += print_hex((unsigned int)va_arg(*ap, unsigned int), 1);
	else if (fmt[i] == 'X')
		ans += print_hex((unsigned int)va_arg(*ap, unsigned int), 2);
	else
		return (ft_putchar_fd(fmt[i], 1));
	return (ans);
}

int	ft_printf(const char *fmt, ...)
{
	int		ans;
	va_list	ap;
	size_t	i;

	i = 0;
	ans = 0;
	va_start(ap, fmt);
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%')
		{
			i++;
			ans += find_type((char *)fmt, i, &ap);
		}
		else
		{
			ft_putchar_fd(fmt[i], 1);
			ans++;
		}
		i++;
	}
	va_end(ap);
	return (ans);
}

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
// }

#include <stdio.h>
int	main(void)
{
	int		ans1;
	int		ans2;
	char	*p;

	p = "123hello, world";
	ans1 = printf("!123\n");
	ans2 = ft_printf("!123\n");
	ans1 = printf("%d %c %s %p\n", INT_MAX, 'a', p, p);
	ans2 = ft_printf("%d %d %s %p\n", INT_MAX, 5, p, p);
	printf("ans1: %d\n", ans1);
	ft_printf("ans2: %d\n", ans2);
	return (0);
}
