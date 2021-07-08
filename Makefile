# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/07 14:55:05 by ewatanab          #+#    #+#              #
#    Updated: 2021/07/08 17:23:18 by ewatanab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libdlist
SRCDIR = ./src/
SRCNAMES = \
SRCS = $(addprefix $(SRCDIR), $(SRCNAMES))
OBJDIR = ./obj/
OBJS = $(SRCNAMES:%.c=$(OBJDIR)%.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -O0

AR = ar
ARFLAGS = -rc

all : $(OBJDIR) $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) -o $@ $^

$(OBJDIR) :
	mkdir -p $@

$(OBJDIR)%.o : $(SRCDIR)%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.phony: all fclean clean re
