
SRCS_DIR			= srcs
SRCS_FILES			= \
					main.c \
					utils.c \
					routine.c \
					setup.c \
					debug.c \
					actions.c \
					clean.c \
					prints.c \
					time.c \

SRCS				= $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))
INCLUDES			= -I .
LIBS				= -lpthread
CC					= gcc

OPTS				= -D TTS_START=1 -D DELAY_THREAD_CREATION=10
CFLAGS				= -Wall -Wextra -Werror ${OPTS} $(INCLUDES)
OBJS				= $(SRCS:.c=.o)
NAME				= philo

ARGS				= 5 800 200 200
OBJ_DIR				= objs

all:				
					@$(MAKE) $(NAME)

$(NAME):			$(OBJS) philo.h
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
