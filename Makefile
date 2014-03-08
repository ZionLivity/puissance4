# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/26 13:13:47 by rbenjami          #+#    #+#              #
#    Updated: 2014/03/08 14:16:17 by rbenjami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include		libft/Makefile.sources

export	CFLAGS	=	-Wall -Wextra -Werror -g

export	CC		=	cc

export	INC		=	-I $(PWD)/libft

NAME		=	puissance4

INC			+=	-I includes

HEAD		=	includes/puissance4.h

SRC_DIR		=	srcs/

FILES		=	$(NAME).c\
				display.c\
				win.c\
				print.c\
				utils.c\
				ia.c


SRC			=	$(addprefix $(SRC_DIR)/, $(FILES))

OBJ			=	$(SRC:.c=.o)

LIB			=	-L./ -lft

OBJ_LIB		=	$(libft/SRC_LIB:.c=.o)

HEAD_LIB	=	libft/libft.h libft/get_next_line.h libft/define_type.h

all:			libft.a $(NAME)

libft.a:		libft/$(OBJ_LIB) $(HEAD_LIB)
	@make -C libft

$(NAME):		$(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)
	@echo ""
	@echo "\033[33m"compilation of $(NAME) : "\033[32m"Success"\033[0m"

$(OBJ):			$(HEAD) libft.a

%.o:			%.c $(HEAD)
	@echo -n .
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:
	@/bin/rm -f $(OBJ)
	@echo "\033[31m"Objects of $(NAME) : deleted"\033[0m"

fclean:			clean
	@/bin/rm -f $(NAME)
	@echo "\033[31m"$(NAME) : deleted"\033[0m"
	@make fclean -C libft
re:				fclean all

.PHONY:			all clean fclean re
