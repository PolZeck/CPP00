# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pledieu <pledieu@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/05 15:37:15 by pledieu           #+#    #+#              #
#    Updated: 2025/06/05 15:37:22 by pledieu          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME    := megaphone
SRC     := megaphone.cpp
OBJ     := $(SRC:.cpp=.o)
CXX     := c++
CXXFLAGS:= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
