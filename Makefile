# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtakashi <rtakashi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 18:49:43 by rtakashi          #+#    #+#              #
#    Updated: 2023/03/02 22:45:24 by rtakashi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_bzero.c ft_putchar_fd.c ft_strlen.c ft_calloc.c ft_putstr_fd.c ft_tolower.c \
ft_atoi.c ft_itoa.c ft_strdup.c ft_toupper.c ft_strlcpy.c ft_memset.c ft_printf.c ft_various_print.c ft_printf_util.c \
	
OBJS = $(SRCS:.c=.o)
# BONUS_OBJS = $(BONUS_SRCS:.c=.o)
# ifdef WITH_BONUS
# OBJS += $(BONUS_OBJS)
# endif
AR = ar
ARFLAGS = rcs
RM = rm -f

.DEFAULT_GOAL :=$(NAME)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

clean: 
	$(RM) $(OBJS) 
# $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# bonus: 
# 	@make WITH_BONUS=1	

.PHONY: all clean fclean re
