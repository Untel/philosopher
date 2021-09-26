
SRCS_DIR			= srcs
SRCS_FILES			= \
	main.c \
	utils.c \
	routine.c \
	setup.c \
	debug.c \
	actions.c \

SRCS				= $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))
INCLUDES			= -I./srcs
LIBS				= -lpthread
CC					= gcc
CFLAGS				= -Wall -Wextra -Werror $(INCLUDES)
OBJS				= $(SRCS:.c=.o)
NAME				= philo

ARGS				= 20 1 3 4 5
OBJ_DIR				= objs

all:				
					@$(MAKE) $(NAME)

$(NAME):			$(OBJS)
					$(CC) $(OBJS) $(LIBS) -o $(NAME)

bonus:				all

run:				all
					./$(NAME) $(ARGS)

norme:
					$(LIBFT_MAKE) norme
					norminette $(SRCS)

clean:
					$(RM) $(OBJS)

fclean:
					$(RM) $(OBJS)
					$(RM) $(NAME)

re:					clean all

fre:				fclean all

.PHONY:				all clean fclean re fre norme bonus run
