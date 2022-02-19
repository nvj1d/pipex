# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/08 02:01:20 by mnajid            #+#    #+#              #
#    Updated: 2022/02/12 19:00:51 by mnajid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex 

cc = gcc 

flags = -Wall -Werror -Wextra

sources = 	childs.c\
			errors.c\
			ft_split.c\
			ft_strjoin.c\
			ft_strlen.c\
			ft_strncmp.c\
			ft_substr.c \
			pipex.c\

objets =  $(sources:.c=.o)

all : $(NAME)

%.o : %.c
	@$(cc) $(flags) -c $^

$(NAME) : $(objets) pipex.h
	@$(cc) $(objets) -o $@
	
clean:
	@rm -rf $(objets)
	
fclean: clean
	@rm -rf $(NAME)
	
re: fclean all