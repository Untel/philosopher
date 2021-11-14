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
CC					= gcc

OPTS				= -D TTS_START=1 -D DELAY_THREAD_CREATION=0 -D USE_PRINTF=0
DEBUG				= 
CFLAGS				= -Wall -Wextra -Werror ${OPTS} $(INCLUDES) $(DEBUG) -MMD
OBJS				= $(SRCS:.c=.o)
NAME				= philo
DEP 				= $(OBJS:.o=.d)

ARGS				= 20 410 300 100
OBJ_DIR				= objs

all:				$(NAME)

$(NAME):			$(OBJS)
					$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

-include $(DEP)

bonus:				all

run:				all
					./$(NAME) $(ARGS)

norme:
					$(LIBFT_MAKE) norme
					norminette $(SRCS)

clean:
					$(RM) $(OBJS) $(DEP)

fclean:				clean
					
					$(RM) $(NAME)

re:					clean all

fre:				fclean all

.PHONY:				all clean fclean re fre norme bonus run
