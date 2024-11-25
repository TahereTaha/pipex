# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/12 18:25:14 by tatahere          #+#    #+#              #
#    Updated: 2024/08/21 11:40:59 by tatahere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR	= ar rcs
RF	= rm -rf
CC	= cc

CFLAGS = -Wall -Wextra -Werror -I$(LIBFTDIR) -g

NAME		=	pipex

LIBFTDIR	=	libft/
LIBFTNAME	=	libft.a
LIBFT		=	$(LIBFTDIR)$(LIBFTNAME)

SRC			:=	main.c			\
				parser.c		\
				errors.c		\
				pipe_utils.c	\
				executer.c		\
				file_utils.c	\

OBJ			:=	${SRC:.c=.o}
DEP			:=	${SRC:.c=.d}

BOBJ			:=	${BSRC:.c=.o}
BDEP			:=	${BSRC:.c=.d}

all: lib $(NAME) Makefile

bonus: .bonus

.bonus: $(BOBJ) $(LIBFT) Makefile
	$(CC) $(CFLAGS) $(BOBJ) $(LIBFT) -o $(NAME)
	touch .bonus

$(NAME): $(OBJ) $(LIBFT) Makefile
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

lib:
	make -C $(LIBFTDIR) all

%.o: %.c Makefile
	$(CC) $(CFLAGS) -MMD -c $< -o $@

clean:
	rm -rf $(DEP) $(OBJ) $(BDEP) $(BOBJ) .bonus
	make -C $(LIBFTDIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus test lib

-include $(DEP)
