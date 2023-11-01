# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 18:41:02 by sebasnadu         #+#    #+#              #
#    Updated: 2023/11/01 18:23:58 by johnavar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS
DEFAULT				= \033[0;39m
GRAY 					= \033[0;90m
RED 					= \033[0;91m
GREEN 				= \033[0;92m
YELLOW 				= \033[0;93m
BLUE 					= \033[0;94m
MAGENTA				= \033[0;95m
CYAN					= \033[0;96m
WHITE 				= \033[0;97m

UNAME					= $(shell uname)
NAME					= so_long

# LIBFT
LIBFT_DIR 		= ./libft
LIBFT_PATH		= $(LIBFT_DIR)/libft.a
LIBFT_FLAGS 	= -L $(LIBFT_DIR) -lft

CC 						= cc
RM 						= rm -rf
PRINTF				= printf

ifeq ($(DEBUG), 1)
	CFLAGS			= -g -Wall -Wextra -Werror -fsanitize=address
else
	CFLAGS			= -Wall -Wextra -Werror
endif

INC_DIR				= ./includes
SRC_DIR				= ./srcs
OBJ_DIR				= ./obj
SRC_SUB_DIRS	= $(shell find $(SRC_DIR) -type d -not -path '$(SRC_DIR)')
SRC						= $(foreach dir, $(SRC_SUB_DIRS), $(wildcard $(dir)/*.c))
OBJ_SUB_DIRS	= $(subst $(SRC_DIR), $(OBJ_DIR), $(SRC_SUB_DIRS))
# OBJ						= $(subst $(SRC_SUB_DIR), $(OBJ_SUB_DIR), $(SRC:.c=.o))
OBJ			= $(subst $(SRC_DIR), $(OBJ_DIR), $(SRC:.c=.o))

ifeq ($(UNAME), Darwin)
	GFLAGS			= -L$(GPATH) -lmlx -framework OpenGL -framework AppKit -lz
	GPATH				= ./minilibx_opengl
	MLX_PATH		= $(GPATH)/libmlx.a
	INCLUDES		= -I./includes -I$(LIBFT_DIR)/includes -I$(GPATH)
	LIBS				= -L$(LIBFT_DIR) -lft
else
	# GFLAGS			= -I$(GPATH) -L$(GPATH) -lmlx -lXext -lX11 -lm -lbsd
	GFLAGS			= -L$(GPATH) -lmlx -lXext -lX11 -lXrender -lm
	GPATH				= minilibx-linux
	MLX_PATH		= $(GPATH)/libmlx.a
	INCLUDES			= -I./includes -I$(LIBFT_DIR)/includes -I$(GPATH)
	LIBS				= -L$(LIBFT_DIR) -lft
endif

# progress bar
SRC_COUNT_TOT := $(shell expr $(shell echo -n $(SRC) | wc -w) - $(shell ls -l $(OBJ_DIR) 2>&1 | grep ".o" | wc -l) + 1)
ifeq ($(shell test $(SRC_COUNT_TOT) -le 0; echo $$?),0)
	SRC_COUNT_TOT := $(shell echo -n $(SRC) | wc -w)
endif
SRC_COUNT := 0
SRC_PCT = $(shell expr 100 \* $(SRC_COUNT) / $(SRC_COUNT_TOT))

all : $(NAME)

$(NAME) : $(OBJ) _libft _mlx
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) $(GFLAGS) -o $@
	@$(PRINTF) "\r%100s\r$(GREEN)$(NAME): Compilation success 🎉!$(DEFAULT)\n"

$(OBJ): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_SUB_DIRS)
	@$(eval SRC_COUNT = $(shell expr $(SRC_COUNT) + 1))
	@$(PRINTF) "\r%100s\r[ %d/%d (%d%%) ] Compiling $(BLUE)$<$(DEFAULT)..." "" $(SRC_COUNT) $(SRC_COUNT_TOT) $(SRC_PCT)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean :
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(GPATH)
	@$(PRINTF) "$(CYAN)Cleaning up object files in $(OBJ_DIR)...$(DEFAULT)\n"
	@$(RM) $(OBJ_DIR)

fclean : clean
	@$(PRINTF) "$(CYAN)Cleaning up $(NAME)...$(DEFAULT)\n"
	@$(RM) $(NAME)
	@$(PRINTF) "$(CYAN)Cleaning up $(LIBFT_PATH)...$(DEFAULT)\n"
	@$(RM) $(LIBFT_PATH)
	@$(PRINTF) "$(CYAN)Cleaning up $(MLX_PATH)...$(DEFAULT)\n"
	@$(RM) $(MLX_PATH)

re : fclean all

_libft :
	@make -C $(LIBFT_DIR)

_mlx :
	@make -C $(GPATH)

norminette: | $(LIBFT_DIR)
	@$(PRINTF) "$(CYAN)\nChecking norm for $(NAME)...$(DEFAULT)\n"
	@norminette -R CheckForbiddenSourceHeader $(SRC_DIR) $(LIBFT_DIR) includes

.PHONY : all clean fclean re _libft _mlx norminette
