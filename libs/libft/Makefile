# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ambouren <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 10:32:43 by ambouren          #+#    #+#              #
#    Updated: 2022/06/29 09:24:46 by ambouren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLOR

purple	=	\033[0;35m
cyan	=	\033[0;36m
green	=	\033[0;32m
neutral	=	\033[0m
red		=	\033[31m

# VARIABLE

NAME	=	libft.a
CC		=	gcc
LC		=	ar cr
CFLAGS	=	-Wall \
			-Wextra \
			-Werror

INC_PATH=	includes/
INCLUDES=	$(NAME:.a=.h)
SRC		=	ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_strlen.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_strcmp.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c  \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \
			get_next_line_utils.c \
			get_next_line.c
SRC_PATH=	$(shell find srcs -type d)
vpath %.c $(foreach rep, $(SRC_PATH), $(rep))

OBJ_PATH=	obj/
OBJ 	=	$(addprefix $(OBJ_PATH),$(SRC:.c=.o))

# COMPILATION

$(NAME)		:	$(OBJ)
	$(LC) $@ $^
	ranlib $@

$(OBJ)		:	$(INC_PATH)$(INCLUDES)

$(OBJ_PATH)%.o		:	%.c
	@mkdir -p obj
	$(CC) -o $@ -c $< $(CFLAGS) -I $(INC_PATH)

# RULES

all			:	$(NAME)

clean		:
	rm -rf $(OBJ_PATH)

fclean		:	clean
	rm -rf $(NAME)

re			:	fclean all

install		:	all
	mv $(NAME) ../

.PHONY	:	all clean fclean re install
