FILES			=	push_swap \
					sort_stack	\
					init_a_to_b	\
					init_b_to_a	\
					utils/check	\
					utils/error	\
					utils/find_node	\
					utils/free	\
					utils/utils	\
					utils/get_node_to_top	\
					utils/stack_utils	\
					commands/push	\
					commands/swap	\
					commands/rotate	\
					commands/rev_rotate

BONUS_FILES		=	./checker_src/checker_bonus \
					./checker_src/utils_bonus \
					./src/sort_stack	\
					./src/init_a_to_b	\
					./src/init_b_to_a	\
					./src/utils/check	\
					./src/utils/error	\
					./src/utils/find_node	\
					./src/utils/free	\
					./src/utils/utils	\
					./src/utils/get_node_to_top	\
					./src/utils/stack_utils	\
					./src/commands/push	\
					./src/commands/swap	\
					./src/commands/rotate	\
					./src/commands/rev_rotate

NAME			=	push_swap
AR_NAME			=	push_swap.a

YELLOW			= \033[1;36m
BLUE			= \033[1;36m
GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -I $(LIBFT_PATH) -g
MFLAGS			=	-s -j16 -C
AR				=	ar rcs
RM				=	rm -rf

LIBFT_PATH		=	lib/libft/
LIBFT			=	$(LIBFT_PATH)libft.a

CHECKER_PATH	=	checker_src/
CHECKER_NAME	=	checker

FILES_PATH		=	src

SRCS			=	$(addprefix $(FILES_PATH)/, $(addsuffix .c, $(FILES)))
BONUS			= 	$(addsuffix .c, $(BONUS_FILES))
OBJS			=	$(SRCS:.c=.o)
BONUS_OBJS			=$(BONUS:.c=.o)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(LIBFT) $(OBJS) 
	@gcc $(OBJS) -o $(NAME) $(LIBFT)
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@make -C $(LIBFT_PATH) clean
	@echo "$(GREEN)-== $(NAME) created! ==-$(DEFAULT)"

$(LIBFT):
	@make $(MFLAGS) $(LIBFT_PATH)

$(AR_NAME): $(LIBFT) $(OBJS) 
	@$(AR) $(AR_NAME) $(OBJS)

bonus:	$(LIBFT) $(AR_NAME) $(BONUS_OBJS)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(CHECKER_NAME)
	@$(RM) $(OBJS) $(BONUS_OBJS)

all: $(NAME)
	
clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@echo "$(YELLOW)-== all created object files deleted! -==$(DEFAULT)"

fclean: clean libclean
	@$(RM) $(NAME)
	@$(RM) $(AR_NAME) 
	@$(RM) $(CHECKER_NAME)
	@echo "$(RED)-== all created files deleted! -==$(DEFAULT)"

libclean:
	@make $(MFLAGS) $(LIBFT_PATH) fclean
	@echo "$(BLUE)-== all created files deleted in libraries! -==$(DEFAULT)"

re: fclean all

push:
	git add .
	git commit -m "commit"
	git push

compile_libs:
	@make -sC lib/libft
	@make clean -sC lib/libft

update:
	git submodule update --init --recursive --remote

run:			re
				./${NAME} <sth>

.PHONY:			all clean fclean re rebonus valgrind run run_bonus makefile
