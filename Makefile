UNAME_S				:= $(shell uname -s)
OS					= 0

ifeq ($(UNAME_S), Linux)
	# Is Linux
else ifeq ($(UNAME_S), Darwin)
	# Is MacOs
endif

LIBS				=

SRCS_DIR			= srcs
SRCS_FILES			= \
	main.c \

SRCS				= $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

INCLUDES			= -I./srcs

CC					= gcc
CFLAGS				= -Ofast -D OS=$(OS) -Wall -Wextra -Werror $(INCLUDES)
OBJS				= $(SRCS:.c=.o)
NAME				= philo

ARGS				= 	
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
