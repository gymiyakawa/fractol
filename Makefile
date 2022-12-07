# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 13:10:06 by gmiyakaw          #+#    #+#              #
#    Updated: 2022/12/07 12:03:33 by gmiyakaw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#
#To  use  MiniLibX  func-
 #      tions,  you'll  need  to
 #      link your software  with
 #      the   MiniLibX  library,
 #      and    several    system
#     frameworks:
#
 #      -lmlx  -framework OpenGL
  #     -framework AppKit
#
 #      You  may  also  need  to
  #     specify  the path to the
   #    MiniLibX library,  using
    #   the -L flag.
#

NAME 	=	fractol

OBJ	=	$(SRC:.c=.o)

NAMELIB	=	libftfractol.a

LIB 	=	-L /Users/gmiyakaw/Documents/fract-ol libftfractol.a

LINK 	=	-lmlx  -framework OpenGL -framework AppKit
SRC		=	fractol.c fractol_utils.c mandelbrot.c inits.c color.c

CC	=	gcc

CFLAGS	=	-Wall -Werror -Wextra

COMP	=	$(CC) $(CFLAGS) $(LIB) $(LINK)

RM		=	rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
				$(MAKE) bonus -C ./libft
				cp ./libft/libft.a $(NAMELIB)
				$(COMP) $(SRC) $(LIB) -o $(NAME) 
				ar rcs $(NAMELIB) $(OBJ)
clean:
	$(RM) $(OBJ)
	$(MAKE) fclean -C ./libft

fclean:	clean
	$(RM) $(NAME)
	$(MAKE) fclean -C ./libft

re:			fclean all

#%.o: %.c
#	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@
#$(NAME): $(OBJ)
#	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

