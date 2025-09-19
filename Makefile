# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zel-ghab <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/16 18:22:13 by zel-ghab          #+#    #+#              #
#    Updated: 2025/09/19 18:44:41 by zel-ghab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###########################################
## ARGUMENTS

NAME 		= minishell
CC		= cc
CFLAGS		= -Wall -Wextra -Werror -g

###########################################
## LIBRARIES

LIBFT         = ./functions/libft

IFLAGS        = -I $(LIBFT)
LDFLAGS       = -L $(LIBFT) -lft

###########################################
## SOURCES

SRC_FILES	= built_in.c

###########################################
## OBJECTS

OBJ_DIR = .cache
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

###########################################
## RULES

all : ${NAME}

${NAME} : ${OBJ_FILES}
	@echo "🛠️  Compiling libraries..."
	@make -s -C ${LIBFT}
	@${CC} ${CFLAGS} ${OBJ_FILES} ${LDFLAGS} -o ${NAME}
	@echo "✅ Compilation successful!"

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean :
	@rm -rf ${OBJ_DIR}
	@make -s clean -C $(LIBFT)
	@echo "🧹 Object files removed."

fclean : clean
	@make -s fclean -C $(LIBFT)
	@rm -rf ${NAME}
	@echo "🧹 Everything is cleaned."

re : fclean all

###########################################
## CUSTOM COMMANDS

linux:
	@$(MAKE) fclean
	@$(MAKE) all OS=LINUX

mac:
	@$(MAKE) fclean
	@$(MAKE) all OS=MAC

.PHONY: all clean fclean re linux mac $(NAME)
