# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ambouren <ambouren@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/29 17:08:30 by ambouren          #+#    #+#              #
#    Updated: 2022/06/30 12:58:14 by ambouren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#  Variable
purple	=	\033[0;35m
cyan	=	\033[0;36m
green	=	\033[0;32m
neutral	=	\033[0m
red		=	\033[31m

CC      =	gcc

CFLAGS  =	-Wall -Wextra -Werror -g
IFLAGS	=	-I includes/ -I libs/libft/includes/ -I libs/libmlx
LDFLAGS	=	-L libs/ -lft -lmlx -lm
EXEC	=	so_long

INC_PATH=	includes/
DEP_PATH=	deps/
OBJ_PATH=	objs/
LIB_PATH=	libs/
SRC_PATH=	$(shell find srcs -type d)
vpath %.c $(foreach rep, $(SRC_PATH), $(rep))
vpath %.a $(LIB_PATH)
LIB		=	libft.a \
			libmlx.a
SRC		=	main.c 
DEP		=	$(addprefix $(DEP_PATH), $(SRC:.c=.d))
OBJ		=	$(addprefix $(OBJ_PATH), $(SRC:.c=.o))
BON_OBJ	=	$(addprefix $(OBJ_PATH), $(BONUS:.c=.o))

#	Compilation
all		:	$(EXEC)

$(EXEC)			:	$(addprefix $(LIB_PATH), $(LIB)) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS)

%.a				:
	@make -C $(@:.a=) install

%_fclean		:
	@make -C $(subst _, , $@)

$(OBJ_PATH)%.o	:	%.c
	@mkdir -p $(OBJ_PATH) $(DEP_PATH)
	$(CC) -o $@ -c $< $(CFLAGS) $(IFLAGS) -MMD
	@mv $(@:.o=.d) $(DEP_PATH)

-include $(DEP)

#	Rule
clean	:
	rm -rf $(OBJ_PATH)
	rm -rf $(DEP_PATH)

fclean	:	clean $(foreach lib, $(LIB),  $(LIB_PATH)$(lib:.a=)_fclean)
	rm -rf $(EXEC)
	rm -rf $(addprefix $(LIB_PATH), $(LIB))
	

re		:	fclean all

.PHONY	:	all clean fclean re bonus
