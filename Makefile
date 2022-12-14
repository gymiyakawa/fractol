# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 13:10:06 by gmiyakaw          #+#    #+#              #
#    Updated: 2022/12/20 15:35:04 by gmiyakaw         ###   ########.fr        #
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

LIB 	=	libft/libft.a

LINK 	=	-lmlx  -framework OpenGL -framework AppKit

SRC		=	fractol.c fractol_utils.c mandelbrot.c inits.c color.c \
			render.c julia.c events.c 
CC	=	gcc

CFLAGS	=	-Wall -Werror -Wextra

COMP	=	$(CC) $(CFLAGS) $(LIB) $(LINK)

RM		=	rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
				$(MAKE) bonus -C ./libft
				$(COMP) $(OBJ) -o $(NAME)
clean:
	$(RM) $(OBJ)
	$(MAKE) fclean -C ./libft

fclean:	clean
	$(RM) $(NAME)
	$(MAKE) fclean -C ./libft

re:			fclean all

