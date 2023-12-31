# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/24 06:11:07 by imurugar          #+#    #+#              #
#    Updated: 2023/04/24 06:11:07 by imurugar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SIMPLE ===================================================================================
NAME = megaphone
# ==========================================================================================

# SRCS =====================================================================================
SRCS_DIR = ./
SRCS = megaphone.cpp
# ==========================================================================================

# FLAGS ====================================================================================
DEBUG = -g -fsanitize=address
FLAGS = $(DEBUG) -std=c++98 -pedantic -Wall -Wextra -Werror
# ==========================================================================================

# UTILS ====================================================================================
CC		= c++ #clang++
RM		= rm -rf
# ==========================================================================================

# OBJS =====================================================================================
OBJS_DIR 	= 	objects/
OBJ 		= 	$(SRCS:.cpp=.o)
OBJS 		= 	$(addprefix $(OBJS_DIR), $(OBJ))
# ==========================================================================================

# COLORS  ==================================================================================
GREEN		=	\e[92;5;118m
YELLOW		=	\e[93;5;226m
GRAY		=	\e[33;2;37m
RESET		=	\e[0m
CURSIVE		=	\e[33;3m
# ==========================================================================================

# FROM SUBJECT =============================================================================
$(OBJS_DIR)%.o :	$(SRCS_DIR)%.cpp
	@mkdir -p $(OBJS_DIR)
	@printf "$(GREEN)    - Compiling $(GRAY)$<$(RESET)\n"
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS)
	@printf "$(GREEN)    - Executable ready.\n$(RESET)"

all: $(NAME)

clean:
	@$(RM) $(OBJS_DIR)

fclean: clean
	@$(RM) $(NAME)
	@printf "$(YELLOW)    - Executable removed.$(RESET)\n"

re: fclean all
# ==========================================================================================

# SUP ======================================================================================
check: $(NAME)
	@/bin/echo
	@/bin/echo "Expected  : SHHHHH... I THINK THE STUDENTS ARE ASLEEP..."
	@/bin/echo -n "Megaphone : "
	@./$(NAME) "shhhhh... I think the students are asleep..."
	@/bin/echo
	@/bin/echo "Expected  : DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF."
	@/bin/echo -n "Megaphone : "
	@./$(NAME) "Damnit ! Sorry students, I thought this thing was off."
	@/bin/echo
	@/bin/echo "Expected  : * LOUD AND UNBEARABLE FEEDBACK NOISE *"
	@/bin/echo -n "Megaphone : "
	@./$(NAME)
	@/bin/echo
# ==========================================================================================

.PHONY: all clean fclean re