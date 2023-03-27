# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 15:08:27 by gmiyakaw          #+#    #+#              #
#    Updated: 2023/03/15 14:10:05 by gmiyakaw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	Target: dependencies	$
#	<tab> action			#

NAME 	=	 libft.a

HEADER	=	libft.h 

SRC 	= 	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
	ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c\
	ft_strlen.c ft_strmapi.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c\
	ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c\
	ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c\
	ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_putchar.c\
	ft_rputnbr.c ft_rputstr.c ft_rputaddress.c ft_rputnbr_base.c ft_rputchar.c \
	ft_strcmp.c ft_str_tolower.c x_calloc.c ft_strjoin_free.c ft_free_array.c ft_atol.c\
	ft_is_nbr.c ft_arrlen.c

OBJ		=	$(SRC:.c=.o) $(PRINTF:.c=.o)

PRINTF	=	./ft_printf/ft_printf.c ./ft_printf/ft_printf_utils.c

BONUS	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJ_B	=	$(BONUS:.c=.o)

CC		=	gcc

RM		=	rm -f

CFLAGS	=	-Wall -Werror -Wextra

all:		$(NAME)

$(NAME):	$(OBJ)
			ar rcs $(NAME) $(OBJ)

bonus:		$(OBJ) $(OBJ_B)
			ar rcs $(NAME) $(OBJ) $(OBJ_B)

clean:
			$(RM) $(OBJ) $(OBJ_B)

fclean: 	clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: all bonus clean fclean re
