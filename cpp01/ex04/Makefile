# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/24 09:01:45 by imurugar          #+#    #+#              #
#    Updated: 2023/04/24 09:01:45 by imurugar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SIMPLE ===================================================================================
NAME = Replacer
# ==========================================================================================

# SRCS =====================================================================================
SRCS_DIR = src/
SRCS =	main.cpp \
		Replace.cpp
# ==========================================================================================

# INCLUDES =================================================================================
INCS_DIR = inc/
INCLUDE = -I$(INCS_DIR)
# ==========================================================================================

# DEPEDENCIES ==============================================================================
DEPS = $(INCS_DIR)/
# ==========================================================================================

# FLAGS ====================================================================================
DEBUG = -g -fsanitize=address
FLAGS = $(DEBUG) -std=c++98 -pedantic -Wall -Wextra -Werror $(INCLUDE)
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
RED 		=   \e[91m
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
	@$(CC)  $(FLAGS) -o $(NAME) $(OBJS)
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
FILE		= "LoremIpsum.txt"
TO_FIND		= "o"
TO_REPLACE	= "holo"
check: $(NAME)
	@printf "$(RED)Wrong arguments:\n$(RESET)"
	@./$(NAME) || true

	@printf "$(RED)Invalid file:\n$(RESET)"
	@./$(NAME) invalid.txt $(TO_FIND) $(TO_REPLACE) || true

	@printf "$(RED)File without permissions:\n$(RESET)"
	@chmod 000 $(FILE)
	@./$(NAME) $(FILE) $(TO_FIND) $(TO_REPLACE) || true
	@chmod 777 $(FILE)

	@printf "$(GREEN)Correct:\n$(RESET)"
	@./$(NAME) $(FILE) $(TO_FIND) $(TO_REPLACE)
	@cat LoremIpsum.txt.replace
# ==========================================================================================

.PHONY: all clean fclean re
