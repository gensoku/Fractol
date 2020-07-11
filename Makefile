#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/02 02:02:13 by tsedigi           #+#    #+#              #
#    Updated: 2016/03/11 11:36:01 by tsedigi          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

#	Program output
NAME = fractol

#	GCC flags -Wall -Wextra $(CFLAGS) -g 
CFLAGS = -Wall -Wextra -Werror
ALL_CFLAGS = $(CFLAGS)

#	Library files
LIBFLAGS = -L./libft -lft -Lmlx -lmlx -framework OpenGL -framework Appkit -framework opencl

#	Termcaps library flag
ifeq ($(OS),Windows_NT)
	LIBFLAGS += -lncurses
else
	LIBFLAGS += -ltermcap
endif

#	Ojects/Sources directories
INC_FRAC = includes/
SRC_FRAC = $(shell find src | grep "\.c$$" | sed "s/\.c$$//g")
INCLUDES += $(addprefix -iquote , $(INC_FRAC))
SRCS += $(addsuffix .c, $(SRC_FRAC))

#	Extern includes
INC_MLX = mlx/
INC_LIBFT = libft/
INCLUDES += $(addprefix -iquote , $(INC_LIBFT))
INCLUDES += $(addprefix -iquote, $(INC_MLX))

#	Final OBJS
OBJS = $(SRCS:.c=.o)

#	Layout
VERBOSE = true

all: header $(NAME) footer

header:
	@echo "\033[33m[\033[4m$(NAME)\033[0m\033[33m] Compile\033[0m"

footer:
	@echo "\033[33m[\033[4m$(NAME)\033[0m\033[33m] Finished\033[0m"

$(NAME): lft lmlx $(OBJS)
ifeq ($(VERBOSE),true)
	@echo "\033[34m. Compile Final .\033[0m $(NAME)"
else
	@printf "\033[34m.\033[0m\n"
endif
	@$(CC) $(ALL_CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME) -g $(LIBFLAGS)

%.o: %.c
ifeq ($(VERBOSE),true)
	@echo "\033[34m. Compile .\033[0m $<"
else
	@printf "\033[34m.\033[0m"
endif
	@$(CC) $(ALL_CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo -e "\033[33m[\033[4m$(NAME)\033[0m\033[33m] >>\033[0m \033[31mCLEAN all object files (*.o)\033[0m"
	@$(RM) $(OBJS)

fclean: clean
	@echo -e "\033[33m[\033[4m$(NAME)\033[0m\033[33m] >>\033[0m \033[31mFCLEAN project binary ($(NAME))\033[0m"
	@$(RM) $(NAME)

re: fclean all

lmlx:
	@echo "\033[33m[\033[4m$(NAME)\033[0m\033[33m] >> Extern dependencies\033[0m"
	@make -C mlx
	@echo "\033[33m[\033[4m$(NAME)\033[0m\033[33m] << Extern dependencies\033[0m"

lmlxclean:
	make -C mlx clean

lft:
	@echo "\033[33m[\033[4m$(NAME)\033[0m\033[33m] >> Extern dependencies\033[0m"
	@make -C libft
	@echo "\033[33m[\033[4m$(NAME)\033[0m\033[33m] << Extern dependencies\033[0m"

lftclean:
	make -C libft clean

lftfclean:
	make -C libft fclean

git:
	@git add .
	@echo "Enter Your Commit :"
	@read var1 ; git commit -m "$$var1"
	@git push