# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hde-ghel <hde-ghel@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/17 16:02:33 by hde-ghel          #+#    #+#              #
#    Updated: 2019/05/28 14:32:43 by hde-ghel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
FLAGS = -Wall -Werror -Wextra
LIBFT = $(LIBDIR)libft.a
SRCDIR = ./src/
OBJDIR = ./obj/
LIBDIR = ./libft/
LIBXDIR = ./minilibx_macos/
INCL = ./includes/
FRAMEWORK = -framework OpenGL -framework Appkit

FILES = $(shell find src -type f | grep -E "\.c$$" | sed 's/src//g')
SRC = $(addprefix $(SRCDIR), $(FILES))
OBJ = $(addprefix $(OBJDIR), $(FILES:.c=.o))
SRCSUBDIR = $(shell find ./src -type d)
OBJSUBDIR = $(SRCSUBDIR:./src%=./obj%)
LONGEST = $(shell echo $(notdir $(SRC)) | tr " " "\n" | \
	awk ' { if ( lenght > x ) { x = lenght; y = $$0 } }END{ print y }' | wc -c )

C_CYAN = \033[96m
C_GREEN = \033[32m
C_RED = \033[32m
C_MAG = \033[1;35m
C_RESET = \033[1;39

all: lib $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCL)
	@printf "$(C_MAG)Compiling %-$(LONGEST)s" $(notdir $<)
	@$(CC) $(FLAGS) -o $@ -c $<
	@printf "  $(C_CYAN)[$(C_GREEN)✔$(C_CYAN)]$(C_RESET)"
	@printf "\r"

lib:
	@make -C $(LIBDIR)
	@echo "$(C_CYAN)Libft compilation       [$(C_GREEN)✔$(C_CYAN)]$(C_RESET)"

$(OBJSUBDIR):
	@mkdir $@

$(NAME): $(OBJSUBDIR) $(OBJ)
	@echo "$(C_CYAN)Fract_ol OBJ creation   [$(C_GREEN)✔$(C_CYAN)] $(C_RESET)"
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT) -L $(LIBXDIR) -lmlx $(FRAMEWORK)
	@echo "$(C_CYAN)Fract_ol OBJ compilation[$(C_GREEN)✔$(C_CYAN)]$(C_RESET)"

clean:
	@rm -rf $(OBJDIR)
	@echo "$(C_CYAN)Deleting fract_ol OBJ   [$(C_GREEN)✔$(C_CYAN)]"
	@make -C $(LIBDIR) clean
	@echo "$(C_CYAN)Deleting Libft OBJ      [$(C_GREEN)✔$(C_CYAN)]$(C_RESET)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(C_CYAN)Deleting libftprintf.a  [$(C_GREEN)✔$(C_CYAN)]"
	@rm -rf $(LIBFT)
	@echo "$(C_CYAN)Deleting libft.a        [$(C_GREEN)✔$(C_CYAN)]$(C_RESET)"

re: fclean all

norm:
	@norminette $(./src/) $(INCL)

.PHONY: norm clean fclean re all
