NAME			= push_swap
NAME_BONUS		= push_swap_bonus

GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m

LIBFT 			= lib/libft/libft.a

CC 				= cc

STANDARD_FLAGS 	= -Wall -Werror -Wextra

REMOVE 			= rm -f

SRCS_DIR		= ./src/
BONUS_SRCS_DIR		= ./bonus/

SRCS 			= $(addprefix $(SRCS_DIR),\
				)

BONUS_SRC 		= $(addprefix $(BONUS_SRCS_DIR),\
				)

all:			${NAME} ${LIBFT} 
bonus:			${NAME_BONUS} ${LIBFT}

${NAME}: 		
				${CC} ${SRCS} ${LIBFT} -o ${NAME}
				make compile_libs
				@echo "$(NAME): $(GREEN)$(NAME) was compiled.$(RESET)"
				@echo

${NAME_BONUS}: 		
				${CC} ${BONUS_SRC} ${LIBFT} -o ${NAME_BONUS}
				@echo "$(NAME_BONUS): $(GREEN)$(NAME_BONUS) was compiled.$(RESET)"
				@echo

${LIBFT}:
				@echo
				make bonus -C lib/libft

clean:
				make clean -C lib/libft
				@echo

fclean:
				${REMOVE} ${NAME} ${NAME_BONUS}
				@echo "${NAME}: ${RED}${NAME} and ${NAME_BONUS} were deleted${RESET}"
				@echo
push:
	git add .
	git commit -m "commit"
	git push

re:				fclean all

re_bonus:	fclean bonus

compile_libs:
	@make -sC lib/libft
	@make clean -sC lib/libft

update:
	git submodule update --init --recursive --remote

run:			re
				./${NAME} <sth>

run_bonus:		re_bonus
				./${NAME_BONUS} <sth>

.PHONY:			all clean fclean re rebonus valgrind run run_bonus makefile
