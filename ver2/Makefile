# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hejang <hejang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/17 17:34:55 by hejang            #+#    #+#              #
#    Updated: 2022/08/17 17:35:36 by hejang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = philo

SRCS	= $(wildcard ${PWD}/*.c)

OBJS	= $(SRCS:.c=.o)

CC = gcc -g3 #-fsanitize=thread
CFLAGS = -Wall -Wextra -Werror -g3

RM = rm -f

all : $(NAME)

%.o : %.c
		$(CC) -c -o $@ $<

$(NAME) : $(OBJS)
		$(CC) $(OBJS) -o $(NAME)	


clean : 
		$(RM) $(RMFLAG) $(OBJS)

fclean : clean
		$(RM) $(RMFLAG) $(NAME)

re : fclean all

 .PHONY : all clean fclean re