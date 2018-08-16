#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vchaus <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/23 16:50:25 by vchaus            #+#    #+#              #
#    Updated: 2018/06/23 16:50:26 by vchaus           ###   ########.fr        #
#                                                                              #
#******************************************************************************#
NAME = ft_retro
CC = clang++
# FLAGS = -Wall -Wextra -Werror -Wno-unused -std=c++98
FLAGS = -Wall -Wextra -Werror
# NCURS = -lncurses -lpanel
NCURS = -lncurses
SRC =	main.cpp \
		ASpaceObject.cpp \
		Game.cpp \
		Space.cpp \
		Ship.cpp \
		Enemy.cpp \
		Bullet.cpp \
		menus.cpp
HEAD =	ft_retro.h
OBJ = $(SRC:.cpp=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(NCURS) -o $(NAME) $(OBJ)

%.o: %.cpp %.hpp $(HEAD)
	$(CC) -c $(FLAGS) $<

%.o: %.cpp $(HEAD)
	$(CC) -c $(FLAGS) $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
