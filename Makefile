# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/25 19:28:21 by ooulcaid          #+#    #+#              #
#    Updated: 2024/03/05 00:15:26 by ooulcaid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror
MLXFLAGS= -lmlx -framework OpenGL -framework AppKit

MAN = srcs/main.c   \
	srcs/algo/fdf.c  \
	srcs/parse/bool.c \
	srcs/parse/error.c \
	srcs/algo/events.c  \
	srcs/algo/init_fdf.c \
	srcs/algo/bresenham.c \
	srcs/algo/mlx_utils.c  \
	srcs/algo/cordinate.c   \
	srcs/algo/dynamic_data.c \
	srcs/parse/extract_data.c \

UTILS = utils/ft_atoi.c\
		utils/is_upper.c\
		utils/is_lower.c \
		utils/ft_bzero.c  \
		utils/ft_split.c   \
		utils/ft_strlen.c   \
		utils/ft_substr.c    \
		utils/ft_strchr.c     \
		utils/ft_strdup.c      \
		utils/ft_strncmp.c      \
		utils/ft_strrchr.c       \
		utils/ft_atoi_base.c      \
		utils/ft_get_lines.c       \
		utils/ft_putendl_fd.c       \
		utils/ft_lstnew_bonus.c      \
		utils/ft_lstclear_bonus.c     \
		utils/ft_lstadd_back_bonus.c   \

MAN_OBJ = $(MAN:.c=.o)
UTILS_OBJ = $(UTILS:.c=.o)

NAME = fdf

srcs/%.o : srcs/%.c srcs/fdf.h
	@$(CC) $(FLAGS) -c $< -o $@

utils/%.o : utils/%.c utils/utils.h
	@$(CC) $(FLAGS) -c $< -o $@
	
all : $(NAME)

$(NAME) : $(MAN_OBJ) $(UTILS_OBJ) 
	@echo "\033[32;1;3m compiling succesfully done"
	@$(CC) $(MAN_OBJ) $(UTILS_OBJ) -o $(NAME) $(MLXFLAGS) -g
	
clean :
	@echo "\033[32;1;3m cleaning..."
	@rm -f $(MAN_OBJ) $(UTILS_OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : clean