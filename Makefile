# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ale-roux <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/06 21:21:04 by ale-roux          #+#    #+#              #
#    Updated: 2022/11/25 17:54:46 by ale-roux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ./src/ft_atoi.c ./src/ft_printf.c ./src/ft_putnbr_binary.c ./src/ft_putnbr_hexdown_fd.c \
		  ./src/ft_putptr_fd.c ./src/ft_putunbr_fd.c ./src/ft_strlen.c ./src/ft_calloc.c \
		  ./src/ft_putchar_fd.c ./src/ft_putnbr_fd.c ./src/ft_putnbr_hexup_fd.c ./src/ft_putstr_fd.c \
		  ./src/ft_strjoin.c
NAME	= minitalk.a
OBJS	=  ${SRCS:.c=.o}

all : ${NAME} server client

.c.o	:
		gcc -Wall -Wextra -Werror -c $< -o ${<:.c=.o}

server: ${NAME}
	gcc -Wall -Werror -Wextra server.c ${NAME} -o server

client: ${NAME}
	gcc -Wall -Werror -Wextra client.c ${NAME} -o client

${NAME} : ${OBJS}
		ar rc ${NAME} ${OBJS}

bonus : all

clean :
		rm -f ${OBJS} server client

fclean : clean
		rm -f ${NAME}

re : fclean all
