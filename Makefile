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

NAME			=	push_swap
AR_NAME			=	push_swap.a

GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -I $(LIBFT_PATH) 
MFLAGS			=	-s -j16 -C
AR				=	ar rcs
RM				=	rm -rf

LIBFT_PATH		=	lib/libft/
LIBFT			=	$(LIBFT_PATH)libft.a

CHECKER_PATH	=	checker/
CHECKER_NAME	=	checker

FILES_PATH		=	src

SRCS			=	$(addprefix $(FILES_PATH)/, $(addsuffix .c, $(FILES)))
OBJS			=	$(SRCS:.c=.o)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(LIBFT) $(OBJS) 
	@gcc $(OBJS) -o $(NAME) $(LIBFT)
	@echo "$(GREEN)-== $(NAME) created! ==-$(DEFAULT)"

$(LIBFT):
	@make $(MFLAGS) $(LIBFT_PATH)

$(AR_NAME): $(LIBFT) $(OBJS) 
	@$(AR) $(AR_NAME) $(OBJS)

bonus:	$(AR_NAME)
	@make $(MFLAGS) $(CHECKER_PATH)

all: $(NAME)
	
clean:
	@$(RM) $(OBJS)
	@make $(MFLAGS) $(CHECKER_PATH) clean
	@echo "$(YELLOW)-== all created object files deleted! -==$(DEFAULT)"

fclean: clean libclean
	@$(RM) $(NAME)
	@$(RM) $(AR_NAME)
	@make $(MFLAGS) $(CHECKER_PATH) fclean
	@echo "$(RED)-== all created files deleted! -==$(DEFAULT)"

libclean:
	@make $(MFLAGS) $(LIBFT_PATH) fclean
	@make $(MFLAGS) $(CHECKER_PATH) fclean
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
