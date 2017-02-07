# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/24 14:41:06 by hkalia            #+#    #+#              #
#    Updated: 2017/02/07 14:58:39 by hkalia           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	checker
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -fsanitize=address

.PHONY: all clean
all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) main.c -o $@

fclean:
	rm -f $(NAME)

re: fclean all
