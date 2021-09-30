
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
INCLUDES			= -I./srcs
LIBS				= -lpthread
CC					= gcc

OPTS				= -D TTS_START=1 -D DELAY_THREAD_CREATION=0
CFLAGS				= -Wall -Wextra -Werror ${OPTS} $(INCLUDES)
OBJS				= $(SRCS:.c=.o)
NAME				= philo

ARGS				= 20000 200 800 400
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
