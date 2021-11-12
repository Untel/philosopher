
SRCS_DIR			= srcs
SRCS_FILES			= \
					main.c \
					utils.c \
					routine.c \
					setup.c \
					actions.c \
					clean.c \
					prints.c \
					time.c \

SRCS				= $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))
INCLUDES			= -I .
LIBS				= -lpthread
CC					= clang

OPTS				= -D TTS_START=1 -D DELAY_THREAD_CREATION=0 -D USE_PRINTF=0 
DEBUG				= 
CFLAGS				= -Wall -Wextra -Werror ${OPTS} $(INCLUDES) $(DEBUG)
OBJS				= $(SRCS:.c=.o)
NAME				= philo

ARGS				= 20 410 300 100
OBJ_DIR				= objs

all:				
					@$(MAKE) $(NAME)

$(NAME):			$(OBJS)
					$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

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

.PHONY:				${NAME} all clean fclean re fre norme bonus run
