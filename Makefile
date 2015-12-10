#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sksourou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/04 16:38:15 by sksourou          #+#    #+#              #
#    Updated: 2015/12/04 16:38:19 by sksourou         ###   ########.fr        #
#                                                                              #
#******************************************************************************#
NAME = fillit

SRCS = srcs/main.c srcs/check_map.c srcs/utils.c srcs/tetri.c \
		srcs/algo.c srcs/best.c srcs/pose.c

OBJS =		$(SRCS:.c=.o)

INCLUDES =	-I libft \
			-I includes

LIBS =		-L libft/ -lft \

FLAGS =		-g -Wall -Wextra -Werror


$(NAME):	$(OBJS)
	@make -C libft/ fclean
	@make -C libft/
	@echo "Create binary"
	@gcc -o $(NAME) $(OBJS) $(LIBS)
	@echo "Complitation ok"

$(OBJS): %.o: %.c
	@gcc $(FLAGS) $(INCLUDES) -c $< -o $@

all:		$(NAME)

clean:
	rm -f	$(OBJS)

fclean: clean
	rm -f	$(NAME)

re: fclean all

.PHONY:	 all clean fclean re
