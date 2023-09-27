# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlima-fe <rlima-fe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/09 12:07:36 by rlima-fe          #+#    #+#              #
#    Updated: 2023/09/09 15:21:54 by rlima-fe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEC = client
NAMES = server
PRINTF = printf/libftprintf.a
CLIENT =	client.c
SERVER =	server.c
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -g
RM = rm -rf

# Colors

DEFAULT = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

all:	$(NAMEC) $(NAMES)

$(NAMEC) : 
		@make -C printf
		$(CC) $(CFLAGS)	$(CLIENT) $(PRINTF) -o $(NAMEC)
		@echo "$(GREEN)Client compiled!$(DEFAULT)"

$(NAMES) : 
		@make -C printf
		$(CC) $(CFLAGS) $(SERVER) $(PRINTF) -o $(NAMES)
		@echo "$(GREEN)Server compiled!$(DEFAULT)"

clean :
		@make clean -C printf
		@echo "$(RED)Cleaned files for you daddy!$(DEFAULT)"

fclean : clean
		@echo "$(YELLOW)Cleaning printf...$(DEFAULT)"
		$(MAKE) -C printf fclean
		@echo "$(YELLOW)Cleaning binary files...$(DEFAULT)"
		$(RM) $(NAMEC) $(NAMES)
		@echo "$(CYAN)Done cleaning.$(DEFAULT)"

re : fclean all

.SILENT: