/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakashi <rtakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:31:17 by rtakashi          #+#    #+#             */
/*   Updated: 2023/03/06 16:51:15 by rtakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_itoa(int n);
void	*ft_memset(void *b, int c, size_t len);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_printf(const char *fmt, ...);
int		get_digit_ptr(unsigned long long ptr);
int		get_digit_u_num(unsigned int u_num, int base);
char	*change_ptr(unsigned long long ptr);
char	*change_base(unsigned int ux, int base);
void	change_letter(char *hex_arr, int case_n);
int		print_str(char *s);
int		print_ptr(unsigned long long p);
int		print_hex(unsigned int u_num, int case_n);
int		print_int(int n);
int		print_un_int(unsigned int u_num);

#endif
