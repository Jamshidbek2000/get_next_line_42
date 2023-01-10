# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 10:01:48 by jergashe          #+#    #+#              #
#    Updated: 2023/01/10 10:06:11 by jergashe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	get_next_line.a
BONUS_NAME 	= 	get_next_line_bonus.a

CC 		= 	cc

FLAGS		= 	-Wall -Wextra -Werror

SRC 		= 	get_next_line.c			\
                get_next_line_utils.c		\

BONUS_SRC	=	get_next_line_bonus.c		\
				get_next_line_utils_bonus.c	\

OBJ 		= 	${SRC:.c=.o}

BONUS_OBJ	=	${BONUS_SRC:.c=.o}

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -c $(SRC)
	ar rc $(NAME) *.o

all: $(NAME)

$(BONUS_NAME): $(BONUS_OBJ)
	$(CC) $(FLAGS) -c $(BONUS_SRC)
	ar rc $(BONUS_NAME) *.o

bonus: $(BONUS_NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus